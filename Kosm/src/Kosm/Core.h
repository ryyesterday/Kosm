#pragma once

#ifdef KM_PLATFORM_WINDOWS
	#ifdef KM_BUILD_DLL
		#define KOSM_API _declspec(dllexport)
	#else
		#define KOSM_API _declspec(dllimport)
	#endif
#else
	#error Kosm only supports Windows
#endif
