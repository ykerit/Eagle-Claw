#include "Preheader.h"
#include "EagleClaw/Core/Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>



namespace EagleClaw {
std::shared_ptr<spdlog::logger> Log::core_logger_;
std::shared_ptr<spdlog::logger> Log::app_logger_;

void Log::Init() {
  spdlog::set_pattern("%^[%T] %n: %v%$");
  core_logger_ = spdlog::stdout_color_mt("EagleClaw");
  core_logger_->set_level(spdlog::level::trace);
  app_logger_ = spdlog::stdout_color_mt("App");
  app_logger_->set_level(spdlog::level::trace);
}

}  // namespace EagleClaw
