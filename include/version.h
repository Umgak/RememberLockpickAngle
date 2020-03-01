#ifndef RLA_VERSION_INCLUDED
#define RLA_VERSION_INCLUDED

#define MAKE_STR_HELPER(a_str) #a_str
#define MAKE_STR(a_str) MAKE_STR_HELPER(a_str)

#define RLA_VERSION_MAJOR	2
#define RLA_VERSION_MINOR	0
#define RLA_VERSION_PATCH	0
#define RLA_VERSION_BETA	0
#define RLA_VERSION_VERSTRING	MAKE_STR(RLA_VERSION_MAJOR) "." MAKE_STR(RLA_VERSION_MINOR) "." MAKE_STR(RLA_VERSION_PATCH) "." MAKE_STR(RLA_VERSION_BETA)

#endif