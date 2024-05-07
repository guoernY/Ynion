#pragma once

#include "Ynion/Core/Base.h"
#include "Ynion/Core/Log.h"
#include <filesystem>

#ifdef YN_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define YN_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { YN##type##ERROR(msg, __VA_ARGS__); YN_DEBUGBREAK(); } }
#define YN_INTERNAL_ASSERT_WITH_MSG(type, check, ...) YN_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define YN_INTERNAL_ASSERT_NO_MSG(type, check) YN_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", YN_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define YN_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define YN_INTERNAL_ASSERT_GET_MACRO(...) YN_EXPAND_MACRO( YN_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, YN_INTERNAL_ASSERT_WITH_MSG, YN_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define YN_ASSERT(...) YN_EXPAND_MACRO( YN_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define YN_CORE_ASSERT(...) YN_EXPAND_MACRO( YN_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define YN_ASSERT(...)
#define YN_CORE_ASSERT(...)
#endif