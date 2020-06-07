#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Resource {

	class RESOURCE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define RS_CORE_TRACE(...)    ::Resource::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RS_CORE_INFO(...)     ::Resource::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RS_CORE_WARN(...)     ::Resource::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RS_CORE_ERROR(...)    ::Resource::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RS_CORE_FATAL(...)    ::Resource::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define RS_TRACE(...)	      ::Resource::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RS_INFO(...)	      ::Resource::Log::GetClientLogger()->info(__VA_ARGS__)
#define RS_WARN(...)	      ::Resource::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RS_ERROR(...)	      ::Resource::Log::GetClientLogger()->error(__VA_ARGS__)
#define RS_FATAL(...)	      ::Resource::Log::GetClientLogger()->fatal(__VA_ARGS__)