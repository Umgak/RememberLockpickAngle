/*
	* RememberLockpickAngle.cpp
	* Prevents the lockpick angle from resetting, optionally requiring a perk.
	* Requires Pattern16 to find addresses

	* Copyright (c) 2026 Sayuri ('Umgak')

	* This program is free software; licensed under the MIT license.
	* You should have received a copy of the license along with this program.
	* If not, see <https://opensource.org/licenses/MIT>.
*/

#include "RememberLockpickAngle.hpp"
#include "Memory.hpp"
#include "Globals.hpp"
#include "DataHandlerUtil.hpp"
#include "Settings.hpp"
#define XBYAK_NO_OP_NAMES // xbyak kinda weird, I don't use those functions but I need to define this anyway
#include "skse64/xbyak/xbyak.h"
#include "skse64_common/BranchTrampoline.h"

namespace RememberLockpickAngle {
	static BGSPerk* g_requiredPerk = nullptr;

	static bool _hasRequiredPerk()
	{
		if (!g_requiredPerk) return true;
		return Globals::hasPerk(*Globals::g_thePlayer, g_requiredPerk);
	}

	static bool _installEntrypoint(uintptr_t entrypoint)
	{
		struct rla_entrypoint : Xbyak::CodeGenerator {
			rla_entrypoint(uintptr_t entrypoint, void* buf) : Xbyak::CodeGenerator(256, buf)
			{
				Xbyak::Label rememberPickAngle;
				Xbyak::Label returnLabel;
				mov(r14, reinterpret_cast<uintptr_t>(_hasRequiredPerk));	// it is with a heavy heart that I inform you that this only causes issues on Windows.
				call(r14);	// on Linux you can litrally just call(_hasRequiredPerk) and it's fine.
				xor_(r14, r14);	// and I didn't think that the Windows memory allocator was THAT radically different I guess.
				test(al, al);
				jnz(rememberPickAngle);
				mov(ptr[rsi + 0xDC], r14d);		// original code at entrypoint
				L(rememberPickAngle);
				jmp(ptr[rip+returnLabel]);
				L(returnLabel);
				dq(entrypoint + 0x7);
			}
		};
		if (!g_branchTrampoline.Create(1024)) {
			_FATALERROR("[FATAL ERROR] Failed to create branch trampoline.");
			return false;
		}
		if (!g_localTrampoline.Create(1024)) {
			_FATALERROR("[FATAL ERROR] Failed to create codegen buffer.");
			return false;
		}
		void* codeBuf = g_localTrampoline.StartAlloc();
		if (!codeBuf) return false;
		rla_entrypoint code(entrypoint, codeBuf);
		g_localTrampoline.EndAlloc(code.getCurr());
		g_branchTrampoline.Write5Branch(entrypoint, uintptr_t(code.getCode()));
		return true;
	}

	bool init() 
	{
		uintptr_t entrypoint = reinterpret_cast<uintptr_t>(SayuLib::Memory::aobScanModule("44 89 b6 dc 00"));
		if (!entrypoint) {
			_FATALERROR("[FATAL ERROR] Failed to find UILockpickingPickBreak entry point. This is fatal. Skipping remainder of init process.");
			return false;
		}
		_DMESSAGE("[DEBUG] UILockpickingPickBreak entrypoint found at address 0x%p", entrypoint);
		if (!_installEntrypoint(entrypoint))
		{
			return false;
		}
		return true;
	}

	void loadSettings(SKSEMessagingInterface::Message* msg)
	{
		if (!msg || msg->type != SKSEMessagingInterface::kMessage_DataLoaded) return;
		Settings::modSettings settings = Settings::getSettings();
		if (settings.moduleName.empty() || settings.perkRelId == 0) return;
		TESForm* form = DataHandlerUtil::getFormFromSettings(settings);
		if (form == nullptr) return;
		const char* name = dynamic_cast<TESFullName*>(form)->GetName();
		if (form->GetFormType() != kFormType_Perk) {
			_WARNING("[WARNING] FormID %08X \"%s\" was found, but was not a PERK object. Falling back to default behavior.", form->formID, name);
			return;
		}
		g_requiredPerk = static_cast<BGSPerk*>(form);
		_MESSAGE("[MESSAGE] Perk \"%s\" [%08X] set as required perk.", name, g_requiredPerk->formID);
		return;
	}
}