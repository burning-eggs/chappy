#pragma once

#include "API.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace chappy {
    class CP_API Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define CP_FATAL(...) ::chappy::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define CP_ERROR(...) ::chappy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CP_WARN(...) ::chappy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CP_INFO(...) ::chappy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CP_TRACE(...) ::chappy::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define CL_FATAL(...) ::chappy::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define CL_ERROR(...) ::chappy::Log::GetClientLogger()->error(__VA_ARGS__)
#define CL_WARN(...) ::chappy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CL_INFO(...) ::chappy::Log::GetClientLogger()->info(__VA_ARGS__)
#define CL_TRACE(...) ::chappy::Log::GetClientLogger()->trace(__VA_ARGS__)