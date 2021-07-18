#pragma once

#include "core/Base.h"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#pragma warning(pop)

namespace GRender
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

#define GD_CORE_TRACE(...) ::GRender::Log::GetCoreLog()->trace(__VA_ARGS__)
#define GD_CORE_INFO(...)  ::GRender::Log::GetCoreLog()->info(__VA_ARGS__)
#define GD_CORE_WARN(...)  ::GRender::Log::GetCoreLog()->warn(__VA_ARGS__)
#define GD_CORE_ERROR(...) ::GRender::Log::GetCoreLog()->error(__VA_ARGS__)
#define GD_CORE_DEBUG(...) ::GRender::Log::GetCoreLog()->debug(__VA_ARGS__)

#define GD_TRACE(...) ::GRender::Log::GetAppLog()->trace(__VA_ARGS__)
#define GD_INFO(...)  ::GRender::Log::GetAppLog()->info(__VA_ARGS__)
#define GD_WARN(...)  ::GRender::Log::GetAppLog()->warn(__VA_ARGS__)
#define GD_ERROR(...) ::GRender::Log::GetAppLog()->error(__VA_ARGS__)
#define GD_DEBUG(...) ::GRender::Log::GetAppLog()->debug(__VA_ARGS__)

}  // namespace GRender
