#pragma once

#include "GLFW/glfw3.h"

#include <events/event.hpp>
#include <functional>
#include <string>

namespace CEngine {
    struct WindowConfig {
        std::string title;
        unsigned int width, height;
        bool vsync;

        WindowConfig(const std::string& title = "CEngine",
                     unsigned int height = 900, unsigned int width = 1600,
                     bool vsync = true) :
            title(title), width(width), height(height), vsync(vsync) {}
    };

    class Window {
    public:
        using EventCallbackFunc = std::function<void(Event&)>;

        Window(const WindowConfig& config = WindowConfig());
        ~Window();

        void Update();
        unsigned int GetWidth() const;
        unsigned int GetHeight() const;

        void SetEventCallback(const EventCallbackFunc& callback);
        void SetVSync(bool enable);
        bool IsVSync();

    private:
        GLFWwindow* window;

        // For sending user pointer to GLFW
        struct Data {
            EventCallbackFunc event_callback;

            std::string title;
            unsigned int width, height;
            bool vsync;
        };

        Data data;
    };
} // namespace CEngine
