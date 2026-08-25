#pragma once
#ifndef RLA_VERSION_HPP
#define RLA_VERSION_HPP

#define RLA_NAME "Remember Lockpick Angle"
#define RLA_SHORT_NAME "RememberLockpickAngle"

#define MAKE_STR_HELPER(a_str) #a_str
#define MAKE_STR(a_str) MAKE_STR_HELPER(a_str)
#define MAKE_DLL_VER_EX(major, minor, patch, sub) ((((major) & 0xFF) << 24) | (((minor) & 0xFF) << 16) | (((patch) & 0xFF) << 8) | ((sub) & 0xFF))
#define MAKE_DLL_VER(major, minor)				  MAKE_DLL_VER_EX(major, minor, 0, 0)

#define RLA_VERSION_MAJOR	5
#define RLA_VERSION_MINOR	0
#define RLA_VERSION_PATCH	0
#define RLA_VERSION_HOTFIX	0

#define RLA_VERSION_VERSTRING		MAKE_STR(RLA_VERSION_MAJOR) "." MAKE_STR(RLA_VERSION_MINOR)
#define RLA_VERSION_VERSTRING_EX	MAKE_STR(RLA_VERSION_MAJOR) "." MAKE_STR(RLA_VERSION_MINOR) "." MAKE_STR(RLA_VERSION_PATCH) "." MAKE_STR(RLA_VERSION_HOTFIX)
#define RLA_DLL_VERSION				MAKE_DLL_VER(RLA_VERSION_MAJOR, RLA_VERSION_MINOR)

#endif
