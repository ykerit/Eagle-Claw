#include <EagleClaw.h>

class Sandbox : public EagleClaw::Application
{
public:
    Sandbox() : Application("Sandbox") { }

    ~Sandbox() { }
};

EagleClaw::Application* EagleClaw::CreateApplication() { return new Sandbox(); }