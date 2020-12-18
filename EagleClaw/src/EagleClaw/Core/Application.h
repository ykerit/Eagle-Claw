#pragma once

#include "Base.h"

namespace EagleClaw {
class Application {
 public:
  Application();

  ~Application();

  void Run();
};

Application* CreateApplication();
}  // namespace EagleClaw