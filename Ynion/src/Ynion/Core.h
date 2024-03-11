#pragma once

#ifdef YN_PLATFORM_WINDOWS
	#ifdef YN_BUILD_DLL
		#define YNION_API __declspec(dllexport)
	#else
		#define YNION_API __declspec(dllimport)
	#endif
#else
	#error Ynion only support Windows!
#endif
