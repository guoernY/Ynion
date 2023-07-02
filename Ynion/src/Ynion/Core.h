#pragma once

#ifdef YN_PLATFORM_WINDOWS
	#ifdef YN_BUILD_DLL
		#define YNION_API _declspec(dllexport)
	#else
		#define YNION_API _declspec(dllimport)
	#endif
#else
	#error YNION only support Windows!
#endif