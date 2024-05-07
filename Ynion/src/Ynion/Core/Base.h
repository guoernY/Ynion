#pragma once

#include <memory>

#include "Ynion/Core/PlatformDetection.h"

#ifdef YN_DEBUG
	#if defined(YN_PLATFORM_WINDOWS)
		#define YN_DEBUGBREAK() __debugbreak()
	#elif defined(YN_PLATFORM_LINUX)
		#include <signal.h>
		#define YN_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define YN_ENABLE_ASSERTS
#else
	#define YN_DEBUGBREAK()
#endif

#define YN_EXPAND_MACRO(x) x
#define YN_STRINGIFY_MACRO(x) #x

#define BIT(x) (1<<x)

#define YN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Ynion {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Ynion/Core/Log.h"
#include "Ynion/Core/Assert.h"