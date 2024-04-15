#pragma once

#include "Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Ynion {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define YN_CORE_TRACE(...)		::Ynion::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define YN_CORE_INFO(...)		::Ynion::Log::GetCoreLogger()->info(__VA_ARGS__)
#define YN_CORE_WARN(...)		::Ynion::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define YN_CORE_ERROR(...)		::Ynion::Log::GetCoreLogger()->error(__VA_ARGS__)
#define YN_CORE_CRITICAL(...)	::Ynion::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define YN_TRACE(...)			::Ynion::Log::GetClientLogger()->trace(__VA_ARGS__)
#define YN_INFO(...)			::Ynion::Log::GetClientLogger()->info(__VA_ARGS__)
#define YN_WARN(...)			::Ynion::Log::GetClientLogger()->warn(__VA_ARGS__)
#define YN_ERROR(...)			::Ynion::Log::GetClientLogger()->error(__VA_ARGS__)
#define YN_CRITICAL(...)		::Ynion::Log::GetClientLogger()->critical(__VA_ARGS__)
