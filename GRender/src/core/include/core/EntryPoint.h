#pragma once

extern GRender::Application* GRender::CreateApplication();

int main()
{
    GRender::Log::Init();
    GRender::Log::GetcoreLog()->warn("Initalized Log!");
    GRender::Log::GetAppLog()->info("Initalized Log!");
    auto app = GRender::CreateApplication();
    app->Run();
    delete app;
}