/*
	* Globals.cpp
	* Registers global singleton and function addresses used by the mod
	* Requires Memory header

	* Copyright (c) 2026 Sayuri ('Umgak')

	* This program is free software; licensed under the MIT license.
	* You should have received a copy of the license along with this program.
	* If not, see <https://opensource.org/licenses/MIT>.
*/
#include "Globals.hpp"
#include "Memory.hpp"
namespace Globals {
	Actor** g_thePlayer = nullptr;
	DataHandler** g_dataHandler = nullptr;
	_lookupFormByID lookupFormByID = nullptr;
	_hasPerk hasPerk = nullptr;

	bool populateGlobals()
	{
		g_thePlayer = reinterpret_cast<Actor**>(SayuLib::Memory::aobScanBase("48 8b 05 ?? ?? ?? ?? 0f 5b c9"));
		g_dataHandler = reinterpret_cast<DataHandler**>(SayuLib::Memory::aobScanBase("48 8b 05 ?? ?? ?? ?? 8b 13"));
		lookupFormByID = reinterpret_cast<_lookupFormByID>(SayuLib::Memory::aobScanModule("48 89 74 24 58 8b f9 48 8d 35", -0x14));
		hasPerk = reinterpret_cast<_hasPerk>(SayuLib::Memory::aobScanBase("e8 ?? ?? ?? ?? 84 c0 74 05 41 ff ?? eb 03", 1, 5));
		
		void* globals[] = {
			g_thePlayer,
			g_dataHandler,
			reinterpret_cast<void*>(lookupFormByID),
			reinterpret_cast<void*>(hasPerk),
		};
		const char* globalNames[] = {
			"g_thePlayer",
			"g_dataHandler",
			"lookupFormByID",
			"hasPerk",
		};
		bool success = true;
		for (size_t i = 0; i < _countof(globals); ++i) {
			if (!globals[i]) {
				_FATALERROR("[FATAL ERROR] Failed to resolve signature for %s!", globalNames[i]);
				success = false;
			} else {
				_DMESSAGE("[DEBUG] Global %s found at address 0x%p", globalNames[i], globals[i]);
			}
		}
		return success;
	}
}