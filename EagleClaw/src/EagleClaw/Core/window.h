#pragma once

namespace EagleClaw {

struct WindowProps {
    size_t width;
    size_t heigth;
    std::string title;
};

class Window {
public:
    using EventCallback = std::function<void()>;

    virtual ~Window()                                      = default;
    virtual void OnUpdate()                                = 0;
    virtual const size_t GetWidth() const                  = 0;
    virtual const size_t GetHeight() const                 = 0;
    virtual void SetEventCallback(EventCallback& callback) = 0;
    virtual void SetVSync(bool enabled)                    = 0;
    virtual bool IsVSync() const                           = 0;
    virtual void* GetNaiveWindow() const                   = 0;
};

}  // namespace EagleClaw