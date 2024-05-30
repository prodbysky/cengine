#include "application.hpp"

#include "events/event.hpp"
#include "events/window_event.hpp"
#include "log.hpp"

#include <GL/gl.h>
#include <memory>

namespace CEngine {

#define BIND_EVENT_FUNC(x)                                                     \
    std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application() {
        window = std::make_unique<Window>();
        window->SetEventCallback(BIND_EVENT_FUNC(OnEvent));
    }
    Application::~Application() {}

    void Application::OnEvent(Event& event) {
        CE_INFO << event;

        EventSender sender(event);

        sender.Send<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));
    }

    bool Application::OnWindowClose(WindowCloseEvent event) {
        (void) event;
        running = false;
        return true;
    }

    void Application::Run() {

        while (running) {
            glClearColor(0.18, 0.18, 0.18, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            window->Update();
        }
    }
} // namespace CEngine
