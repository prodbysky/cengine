#pragma once
#include "event.hpp"

#include <sstream>

namespace CEngine {
    class MouseButtonEvent : public Event {
    public:
        inline int GetMouseButton() const { return button; }

        EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        MouseButtonEvent(int button) : button(button) {}

        int button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << button;
            return ss.str();
        }

        EVENT_TYPE(EventType::MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent {
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << button;
            return ss.str();
        }

        EVENT_TYPE(EventType::MouseButtonReleased)
    };

    class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(float x, float y) : mouse_x(x), mouse_y(y) {}

        inline float GetX() const { return mouse_x; }
        inline float GetY() const { return mouse_y; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << mouse_x << ", " << mouse_y;
            return ss.str();
        }

        EVENT_TYPE(EventType::MouseMoved)
        EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float mouse_x, mouse_y;
    };

    class MouseScrollEvent : public Event {
    public:
        MouseScrollEvent(float xOffset, float yOffset) :
            x_offset(xOffset), y_offset(yOffset) {}

        inline float GetXOffset() const { return x_offset; }
        inline float GetYOffset() const { return y_offset; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", "
               << GetYOffset();
            return ss.str();
        }

        EVENT_TYPE(EventType::MouseScroll)
        EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float x_offset, y_offset;
    };
} // namespace CEngine
