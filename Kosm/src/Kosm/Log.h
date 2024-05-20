#pragma once

#include "Kosm/Core.h"
#include "spdlog/spdlog.h"

namespace Kosm {

	class KOSM_API Log
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
#define KOSM_CORE_FATAL(...)   ::Kosm::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define KOSM_CORE_ERROR(...)   ::Kosm::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KOSM_CORE_WARN(...)    ::Kosm::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KOSM_CORE_INFO(...)    ::Kosm::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KOSM_CORE_TRACE(...)   ::Kosm::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define KOSM_FATAL(...)        ::Kosm::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define KOSM_ERROR(...)        ::Kosm::Log::GetClientLogger()->error(__VA_ARGS__)
#define KOSM_WARN(...)         ::Kosm::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KOSM_INFO(...)         ::Kosm::Log::GetClientLogger()->info(__VA_ARGS__)
#define KOSM_TRACE(...)        ::Kosm::Log::GetClientLogger()->trace(__VA_ARGS__)
