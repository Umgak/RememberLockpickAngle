# RememberLockpickAngle
An SKSE64 Plugin that disables resetting the lockpick angle after breaking the previous pick.

Optionally, allows the user to specify a perk requirement.

## Dependencies
* [SKSE64](https://skse.silverlock.org/)

## Installation
Install with your favorite mod manager, or unzip the release into `Skyrim Special Edition/Data` directory.

## Configuration
By default, no perk is required. However, a perk can be set to be required in the `RememberLockpickAngle.ini` file.

Specify the mod file that provides the Perk as the `modName`, and the RELATIVE form ID as the `requiredPerk`. 

As an example, if you want the "Novice Locks" perk to be required, the following configuration would suffice:
```ini
[RememberLockpickAngle]
; mod filename to search for PERK record
modName = Skyrim.esm
; PERK record's formID, relative to mod file
requiredPerk = F392A
```
Similarly, if (for some reason) you wanted to require the Vampire Lord's Power of the Grave:
```ini
[RememberLockpickAngle]
; mod filename to search for PERK record
modName = Dawnguard.esm
; PERK record's formID, relative to mod file
requiredPerk = 5998
```
## Build Dependencies
* [Script Extender Common](https://github.com/ianpatt/common)
* [SKSE64](https://github.com/ianpatt/skse64)

## Build Instructions
Requires MSBuild to be added to your PATH.
```ps
git clone git@github.com:Umgak/RememberLockpickAngle.git
./scripts/build.ps1
```
The .dll will be output in `x64/Release/RememberLockpickAngle.dll`


## License
[MIT (c) Sayuri ('Umgak')](https://github.com/Umgak/RememberLockpickAngle/LICENSE)