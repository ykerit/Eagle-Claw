#pragma once

#include "EagleClaw/Core/window.h"

namespace EagleClaw {

class GWindow : public Window {
public:
    GWindow(const size_t width, const size_t height);
    ~GWindow();

    void OnUpdate() override;

    const size_t GetWidth() const override;

    const size_t GetHeight() const override;

    void SetEventCallback(EventCallback& callback) override;

    void SetVSync(bool enabled) override;

    bool IsVSync() const override;

    void* GetNaiveWindow() const override;

private:
    void Init();
    void ShutDown();
};

}  // namespace EagleClaw