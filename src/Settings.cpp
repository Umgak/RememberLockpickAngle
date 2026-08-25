/*
	* Settings.cpp
	* Loads and returns the settings

	* Copyright (c) 2026 Sayuri ('Umgak')

	* This program is free software; licensed under the MIT license.
	* You should have received a copy of the license along with this program.
	* If not, see <https://opensource.org/licenses/MIT>.
*/

#include "RLA_Version.hpp"
#include "Settings.hpp"
#include <string>
#include <format>
#include "inicpp/inicpp.hpp"
namespace Settings {
	modSettings getSettings() 
	{
		std::string modConfigPath = std::format(R"(Data\SKSE\Plugins\{}.ini)", RLA_SHORT_NAME);
		modSettings settings;
		inicpp::IniManager _ini(modConfigPath);
		std::string perkString = _ini[RLA_SHORT_NAME].toString("requiredPerk");
		settings.perkRelId = std::stoul(perkString, nullptr, 0x10); // inicpp does not have any builtin for hexadecimal, convert string->int
		settings.moduleName = _ini[RLA_SHORT_NAME].toString("modName");
		return settings;
	}
}