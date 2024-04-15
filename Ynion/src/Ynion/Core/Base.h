#pragma once

#include <memory>

#ifdef YN_DEBUG
	#if defined(YN_PLATFORM_WINDOWS)
		#define YN_DEBUGBREAK() __debugbreak()
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define YN_ENABLE_ASSERTS
#else
	#define YN_DEBUGBREAK()
#endif

#ifdef YN_ENABLE_ASSERTS
	#define YN_ASSERT(x, ...) { if(!(x)) { YN_ERROR("Assertion Failed: {0}", __VA_ARGS__); YN_DEBUGBREAK(); } }
	#define YN_CORE_ASSERT(x, ...) { if(!(x)) { YN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); YN_DEBUGBREAK(); } }
#else
	#define YN_ASSERT(x, ...)
	#define YN_CORE_ASSERT(x, ...)
#endif

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