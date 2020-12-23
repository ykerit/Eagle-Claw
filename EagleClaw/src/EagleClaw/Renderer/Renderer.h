#pragma once

namespace EagleClaw
{

class Renderer
{
public:
    static void Init();
    static void ShutDown();
    static void OnWindowResize();
    static void Submit();
};

}