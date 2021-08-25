#pragma once

// Compiler version are taken from: https://github.com/cxxstuff/cxx_detect

#define NOVA_CLANG 0
#define NOVA_GCC   0
#define NOVA_MSVC  0

#define NOVA_MAKE_VER(MAJOR, MINOR, PATCH) ((MAJOR) * 10000000 + (MINOR) * 100000 + (PATCH))

#if defined(_MSC_VER) && defined(_MSC_FULL_VER)
	#undef NOVA_MSVC
	#if _MSC_VER == _MSC_FULL_VER / 10000
		#define NOVA_MSVC NOVA_MAKE_VER(_MSC_VER / 100, _MSC_VER % 100, _MSC_FULL_VER % 10000)
	#else
		#define NOVA_MSVC NOVA_MAKE_VER(_MSC_VER / 100, (_MSC_FULL_VER / 100000) % 100, _MSC_FULL_VER % 100000)
	#endif
#elif defined(__GNUC__) && defined(__GNUC_MINOR__) && defined(__GNUC_PATCHLEVEL__)
	#undef NOVA_GCC
	#define NOVA_GCC NOVA_MAKE_VER(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#elif defined(__clang__) && defined(__clang_minor__)
	#undef NOVA_CLANG
	#define NOVA_CLANG NOVA_MAKE_VER(__clang_major__, __clang_minor__, __clang_patchlevel__)
#else
	#error "[nova/types.h] Unable to detect C/C++ compiler."
#endif

// compiler warnings helpers are taken from: https://github.com/onqtam/doctest

#if NOVA_MSVC
	#define NOVA_MSVC_SUPPRESS_WARNING_PUSH __pragma(warning(push))
	#define NOVA_MSVC_SUPPRESS_WARNING(w) __pragma(warning(disable : w))
	#define NOVA_MSVC_SUPPRESS_WARNING_POP __pragma(warning(pop))
#else
	#define NOVA_MSVC_SUPPRESS_WARNING_PUSH
	#define NOVA_MSVC_SUPPRESS_WARNING(w)
	#define NOVA_MSVC_SUPPRESS_WARNING_POP
#endif

#if NOVA_GCC
	#define NOVA_PRAGMA_TO_STR(x) _Pragma(#x)
	#define NOVA_GCC_SUPPRESS_WARNING_PUSH _Pragma("GCC diagnostic push")
	#define NOVA_GCC_SUPPRESS_WARNING(w) NOVA_PRAGMA_TO_STR(GCC diagnostic ignored w)
	#define NOVA_GCC_SUPPRESS_WARNING_POP _Pragma("GCC diagnostic pop")
#else
	#define NOVA_GCC_SUPPRESS_WARNING_PUSH
	#define NOVA_GCC_SUPPRESS_WARNING(w)
	#define NOVA_GCC_SUPPRESS_WARNING_POP
#endif

#if NOVA_CLANG
	#define NOVA_PRAGMA_TO_STR(x) _Pragma(#x)
	#define NOVA_CLANG_SUPPRESS_WARNING_PUSH _Pragma("clang diagnostic push")
	#define NOVA_CLANG_SUPPRESS_WARNING(w) NOVA_PRAGMA_TO_STR(clang diagnostic ignored w)
	#define NOVA_CLANG_SUPPRESS_WARNING_POP _Pragma("clang diagnostic pop")
#else
	#define NOVA_CLANG_SUPPRESS_WARNING_PUSH
	#define NOVA_CLANG_SUPPRESS_WARNING(w)
	#define NOVA_CLANG_SUPPRESS_WARNING_POP
#endif
