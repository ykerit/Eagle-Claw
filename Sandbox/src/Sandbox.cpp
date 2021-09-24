#include "Sandbox2D.h"
#include "core/EntryPoint.h"

class Sandbox : public GRender::Application
{
public:
    Sandbox()
        : Application("Sandbox")
    {
        PushLayerOverlay(new Sandbox2D());
    }

    ~Sandbox() {}
};

GRender::Application *GRender::CreateApplication()
{
    return new Sandbox();
}