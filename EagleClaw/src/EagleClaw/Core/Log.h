#pragma once

#include <spdlog/spdlog.h>

#include "Base.h"

namespace EagleClaw {
class Log {
 public:
  static void Init();
  inline static std::shared_ptr<spdlog::logger>& GetCoreLog() {
    return core_logger_;
  }
  inline static std::shared_ptr<spdlog::logger>& GetAppLog() {
    return app_logger_;
  }

 private:
  static std::shared_ptr<spdlog::logger> core_logger_;
  static std::shared_ptr<spdlog::logger> app_logger_;
};
}  // namespace EagleClaw
