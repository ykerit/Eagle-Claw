#pragma once

#include "EagleClaw/Core/Base.h"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#pragma warning(pop)

namespace EagleClaw
{
    class Log
    {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLog() { return core_logger_; }
        inline static std::shared_ptr<spdlog::logger>& GetAppLog() { return app_logger_; }

    private:
        static std::shared_ptr<spdlog::logger> core_logger_;
        static std::shared_ptr<spdlog::logger> app_logger_;
    };

#define EGC_CORE_TRACE(...) ::EagleClaw::Log::GetCoreLog()->trace(__VA_ARGS__)
#define EGC_CORE_INFO(...)  ::EagleClaw::Log::GetCoreLog()->info(__VA_ARGS__)
#define EGC_CORE_WARN(...)  ::EagleClaw::Log::GetCoreLog()->warn(__VA_ARGS__)
#define EGC_CORE_ERROR(...) ::EagleClaw::Log::GetCoreLog()->error(__VA_ARGS__)
#define EGC_CORE_DEBUG(...) ::EagleClaw::Log::GetCoreLog()->debug(__VA_ARGS__)

#define EGC_TRACE(...) ::EagleClaw::Log::GetCoreLog()->trace(__VA_ARGS__)
#define EGC_INFO(...)  ::EagleClaw::Log::GetCoreLog()->info(__VA_ARGS__)
#define EGC_WARN(...)  ::EagleClaw::Log::GetCoreLog()->warn(__VA_ARGS__)
#define EGC_ERROR(...) ::EagleClaw::Log::GetCoreLog()->error(__VA_ARGS__)
#define EGC_DEBUG(...) ::EagleClaw::Log::GetCoreLog()->debug(__VA_ARGS__)

}  // namespace EagleClaw
