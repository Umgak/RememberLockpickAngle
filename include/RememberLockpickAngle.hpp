/*
	* RememberLockpickAngle.hpp
	* See RememberLockpickAngle.cpp

	* Copyright (c) 2026 Sayuri ('Umgak')

	* This program is free software; licensed under the MIT license.
	* You should have received a copy of the license along with this program.
	* If not, see <https://opensource.org/licenses/MIT>.
*/

#pragma once
#ifndef REMEMBER_LOCKPICK_ANGLE_HPP
#define REMEMBER_LOCKPICK_ANGLE_HPP
#include "skse64/PluginAPI.h"
namespace RememberLockpickAngle {
	bool init();
	void loadSettings(SKSEMessagingInterface::Message* msg);
}
#endif