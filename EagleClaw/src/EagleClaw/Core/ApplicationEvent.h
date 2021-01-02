#pragma once

#include "EagleClaw/Core/Event.h"

namespace EagleClaw
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
        WindowResizeEvent() = default;
    };
}  // namespace EagleClaw