#pragma once

#include "core/Base.h"
#include "core/Application.h"

extern GRender::Application *GRender::CreateApplication();

int main(int argc, char **argv)
{
    GRender::Log::Init();
    GRender::Log::GetCoreLog()->warn("Initalized Log!");
    GRender::Log::GetAppLog()->info("Initalized Log!");
    auto app = GRender::CreateApplication();
    app->Run();
    delete app;
}