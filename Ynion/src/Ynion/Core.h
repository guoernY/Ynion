#pragma once

#include <memory>

#ifdef YN_PLATFORM_WINDOWS
#if YN_DYNAMIC_LINK
	#ifdef YN_BUILD_DLL
		#define YNION_API __declspec(dllexport)
	#else
		#define YNION_API __declspec(dllimport)
	#endif
#else
	#define YNION_API
#endif
#else
	#error Ynion only support Windows!
#endif

#ifdef YN_DEBUG
	#define YN_ENABLE_ASSERTS
#endif

#ifdef YN_ENABLE_ASSERTS
	#define YN_ASSERT(x, ...) { if(!(x)) { YN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define YN_CORE_ASSERT(x, ...) { if(!(x)) { YN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define YN_ASSERT(x, ...)
	#define YN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)

#define YN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Ynion {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}