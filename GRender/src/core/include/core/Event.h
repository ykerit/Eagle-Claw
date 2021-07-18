#pragma once

#include <sstream>
#include <string>

namespace GRender
{
#define BIT(x) (1 << x)

    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize
    };

    enum EventCategory
    {
        None = 0,
        ApplicationEvent = BIT(0),
        InputEvent = BIT(1),
        KeyBoardEvent = BIT(2),
        MouseEvent = BIT(3)
    };

#define IMP_EVENT_TYPE(type)                                       \
    virtual EventType GetType() const override { return type; }    \
    virtual const char* GetName() const override { return #type; } \
    static EventType GetStaticType() { return type; }

#define IMP_EVENT_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return category; }

    class Event
    {
    public:
        bool handled = false;

        virtual ~Event() = default;

        virtual EventType GetType() const = 0;
        virtual const char* GetName() const = 0;

        virtual int GetCategoryFlags() const = 0;
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event& event) : event_(event) { }

        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (event_.GetType() == T::GetStaticType())
            {
                event_.handled |= func(static_cast<T&>(event_));
                return true;
            }
            return false;
        }

    private:
        Event& event_;
    };
}  // namespace GRender