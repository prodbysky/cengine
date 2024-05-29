#pragma once

#include "key_event.hpp"

#include <sstream>
namespace CEngine {

    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() {}

        EVENT_TYPE(EventType::WindowClose)
        EVENT_CATEGORY(EventCategoryWindow)
    };

    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) :
            width(width), height(height) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: (" << width << ", " << height << ")";
            return ss.str();
        }

        EVENT_TYPE(EventType::WindowResize)
        EVENT_CATEGORY(EventCategoryWindow)

    private:
        unsigned int width, height;
    };

    class WindowFocusEvent : public Event {
    public:
        WindowFocusEvent() {}

        EVENT_TYPE(EventType::WindowFocus)
        EVENT_CATEGORY(EventCategoryWindow)
    };

    class WindowLostFocusEvent : public Event {
    public:
        WindowLostFocusEvent() {}

        EVENT_TYPE(EventType::WindowLostFocus)
        EVENT_CATEGORY(EventCategoryWindow)
    };
    class WindowMovedEvent : public Event {
    public:
        WindowMovedEvent() {}

        EVENT_TYPE(EventType::WindowMoved)
        EVENT_CATEGORY(EventCategoryWindow)
    };

} // namespace CEngine
