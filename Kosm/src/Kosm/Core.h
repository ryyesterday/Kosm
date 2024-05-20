#pragma once

#ifdef KOSM_PLATFORM_WINDOWS
	#ifdef KOSM_BUILD_DLL
		#define KOSM_API _declspec(dllexport)
	#else
		#define KOSM_API _declspec(dllimport)
	#endif
#else
	#error Kosm only supports Windows
#endif

#ifdef KOSM_ENABLE_ASSERTS
	#define KOSM_ASSERT(x, ...) { if(!(x)) { KOSM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define KOSM_CORE_ASSERT(x, ...) { if(!(x)) { KOSM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define KOSM_ASSERT(x, ...)
	#define KOSM_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
