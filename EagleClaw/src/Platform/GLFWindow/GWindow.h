#pragma once

#include "EagleClaw/Core/window.h"

namespace EagleClaw {

class GWindow : public Window {
public:
    GWindow(const WindowProps& windowProps);
    ~GWindow();

    void OnUpdate() override;

    const size_t GetWidth() const override {
        return width_;
    }

    const size_t GetHeight() const override {
        return height_;
    }

    void SetEventCallback(EventCallback& callback) override;

    void SetVSync(bool enabled) override;

    bool IsVSync() const override;

    void* GetNaiveWindow() const override {
        return window_;
    }

private:
    void Init(const WindowProps& windowProps);
    void ShutDown();

    GLFWwindow* window_;
    size_t width_;
    size_t height_;
    std::string title_;
    bool enableVSync_;
};

}  // namespace EagleClaw