/*
	* Settings header
	* Loads and returns the settings

	* Copyright (c) 2026 Sayuri ('Umgak')

	* This program is free software; licensed under the MIT license.
	* You should have received a copy of the license along with this program.
	* If not, see <https://opensource.org/licenses/MIT>.
*/
#pragma once
#ifndef SETTINGS_HPP
#define SETTINGS_HPP

namespace Settings {
	struct modSettings {
		UInt32 perkRelId = 0;
		std::string moduleName;
	};

	modSettings getSettings();
}
#endif