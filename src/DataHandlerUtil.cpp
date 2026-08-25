/*
	* DataHandlerUtil.cpp
	* Internal functions for manipulation of DataHandler class
	* Requires Settings and Globals

	* Copyright (c) 2026 Sayuri ('Umgak')

	* This program is free software; licensed under the MIT license.
	* You should have received a copy of the license along with this program.
	* If not, see <https://opensource.org/licenses/MIT>.
*/
#include "DataHandlerUtil.hpp"
#include "Globals.hpp"
#include "skse64/GameData.h"
namespace DataHandlerUtil {
	TESForm* getFormFromSettings(Settings::modSettings settings)
	{
		if (settings.moduleName.empty() || settings.perkRelId == 0) return nullptr; // nothing to do
		const char* modName = settings.moduleName.c_str();
		DataHandler* dh = *Globals::g_dataHandler; // get the data handler singleton
		const ModInfo* mod = dh->LookupModByName(modName);
		if (!mod) {
			_WARNING("[WARNING] Unable to find any mod named %s! The settings file may refer to a mod that is not installed.", modName);
			return nullptr;
		}
		UInt32 formID = mod->GetFormID(settings.perkRelId); // skse has a builtin for this? since when?
		TESForm* form = Globals::lookupFormByID(formID);
		if (!form) {
			_WARNING("[WARNING] Form %08X not found in file %s, even though the file was found.", formID, modName);
			return nullptr;
		}
		return form;
	}
}