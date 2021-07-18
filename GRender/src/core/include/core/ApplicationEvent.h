#pragma once

#include "core/Event.h"

namespace GRender
{
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;
        IMP_EVENT_TYPE(EventType::WindowClose);
        IMP_EVENT_CATEGORY(EventCategory::ApplicationEvent)
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(size_t width, size_t height) : width_(width), height_(height) { }
        const size_t GetWidth() const { return width_; }
        const size_t GetHeight() const { return height_; }

        const std::string ToString() const
        {
            std::stringstream ss;
            ss << "Window Resize Event: " << width_ << " " << height_;
            return ss.str();
        }

        IMP_EVENT_TYPE(EventType::WindowResize);
        IMP_EVENT_CATEGORY(EventCategory::ApplicationEvent)

    private:
        size_t width_;
        size_t height_;
    };
}  // namespace GRender