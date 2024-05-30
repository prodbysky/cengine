#pragma once

#include <events/window_event.hpp>
#include <memory>
#include <window.hpp>

namespace CEngine {
    class Application {
    public:
        Application();
        virtual ~Application();

    public:
        void Run();
        void OnEvent(Event& event);

    private:
        bool OnWindowClose(WindowCloseEvent event);

    private:
        std::unique_ptr<Window> window;
        bool running = true;
    };

    Application* CreateApplication();
} // namespace CEngine
