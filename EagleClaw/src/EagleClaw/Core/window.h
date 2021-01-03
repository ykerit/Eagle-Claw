#pragma once

#include <functional>
#include <memory>
#include <string>

#include "EagleClaw/Core/Event.h"

namespace EagleClaw
{
    struct WindowProps
    {
        size_t width;
        size_t heigth;
        std::string title;

        WindowProps(const std::string& title_ = "App", int width_ = 1600, int height_ = 800)
            : title(title_), width(width_), heigth(height_)
        {
        }
    };

    class Window
    {
    public:
        using EventCallback = std::function<void(Event&)>;

        virtual ~Window() = default;
        virtual void OnUpdate() = 0;
        virtual const size_t GetWidth() const = 0;
        virtual const size_t GetHeight() const = 0;
        virtual void SetEventCallback(const EventCallback& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
        virtual void* GetNaiveWindow() const = 0;

        static std::unique_ptr<Window> Create(const WindowProps& props);
    };

}  // namespace EagleClaw