/*
	* Globals.hpp
	* Global functions and singletons required by the mod
	* See Globals.cpp

	* Copyright (c) 2026 Sayuri ('Umgak')

	* This program is free software; licensed under the MIT license.
	* You should have received a copy of the license along with this program.
	* If not, see <https://opensource.org/licenses/MIT>.
*/

#pragma once
#ifndef GLOBALS_HPP
#define GLOBALS_HPP
#include "skse64/GameData.h"
namespace Globals {
	typedef TESForm* (*_lookupFormByID)(UInt32 formId);
	typedef bool (*_hasPerk)(Actor* actor, BGSPerk* perk);

	extern Actor** g_thePlayer;
	extern DataHandler** g_dataHandler;
	extern _lookupFormByID lookupFormByID;
	extern _hasPerk hasPerk;

	bool populateGlobals();
}
#endif