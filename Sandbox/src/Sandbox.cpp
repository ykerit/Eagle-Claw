#include <EagleClaw.h>
#include <EagleClaw/Core/EntryPoint.h>

#include "Sandbox2D.h"

class Sandbox : public EagleClaw::Application
{
public:
    Sandbox() : Application("Sandbox") { PushLayer(new Sandbox2D()); }

    ~Sandbox() { }
};

EagleClaw::Application* EagleClaw::CreateApplication() { return new Sandbox(); }