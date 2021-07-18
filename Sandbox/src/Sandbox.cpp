#include <EagleClaw.h>
#include <EagleClaw/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "math.h"

class Sandbox : public EagleClaw::Application
{
public:
    Sandbox() : Application("Sandbox") { PushLayerOverlay(new Sandbox2D()); }

    ~Sandbox() { }
};

EagleClaw::Application* EagleClaw::CreateApplication() { return new Sandbox(); }