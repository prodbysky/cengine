#pragma once
#include "event.hpp"

#include <sstream>

namespace CEngine {

    // More abstract class to reduce code repetition
    class KeyEvent : public Event {
    public:
        inline int GetCode() const { return keycode; }

        EVENT_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

    protected:
        KeyEvent(int keycode) : keycode(keycode) {}
        int keycode;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keycode, int repeat_count) :
            KeyEvent(keycode), repeat_count(repeat_count) {}
        inline int GetRepeatCount() const { return repeat_count; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << keycode << " (" << repeat_count
               << " repeats)";
            return ss.str();
        }

        EVENT_TYPE(EventType::KeyPressed)
    private:
        int repeat_count;
    };

    class KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}
        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << keycode;
            return ss.str();
        }

        EVENT_TYPE(EventType::KeyReleased)
    };
} // namespace CEngine
