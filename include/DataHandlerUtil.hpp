/*
	* DataHandlerUtil.hpp
	* Internal functions for manipulation of DataHandler class
	* Requires Settings and GameData

	* Copyright (c) 2026 Sayuri ('Umgak')

	* This program is free software; licensed under the MIT license.
	* You should have received a copy of the license along with this program.
	* If not, see <https://opensource.org/licenses/MIT>.
*/
#pragma once
#ifndef DATA_HANDLER_UTIL_HPP
#define DATA_HANDLER_UTIL_HPP
#include "skse64/GameData.h"
#include "Settings.hpp"

namespace DataHandlerUtil {
	TESForm* getFormFromSettings(Settings::modSettings settings);
}
#endif