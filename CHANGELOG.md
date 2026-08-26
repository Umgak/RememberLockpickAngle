# Changelog

## Unreleased
* Refactored so that if global functions fail to populate, the mod will failsafe instead of throwing an error. No perk requirement functionality will be supported in this mode.

## [v5.0.1] - 2026-08-26
* Fixed an issue which caused the mod to fail to initialize on Windows.
  - This was due to differences in the Windows and Linux memory mappers. Linux mapped the dll into call(rel32) distance, Windows doesn't. I don't use Windows so I couldn't have caught this.
* Fixed an issue which caused a crash with an empty settings file on Windows.
  - The Linux version of std::stoul is non-compliant and does not throw std::invalid_argument exceptions on empty input. Once again, I don't use Windows so I couldn't test this.

## [v5.0] - 2026-08-25
* Full rewrite.
* No longer dependent on Address Library.
* Compatible with EVERY version of Skyrim Special Edition supported by Skyrim Script Extender.