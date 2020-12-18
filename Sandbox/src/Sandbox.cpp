#include <EagleClaw.h>

class Sandbox : public EagleClaw::Application {
 public:
  Sandbox() {}

  ~Sandbox() {}
};

EagleClaw::Application* EagleClaw::CreateApplication() { return new Sandbox(); }