#pragma once

namespace CEngine {
    class Application {
    public:
        Application();
        virtual ~Application();

    public:
        void Run();
    };

    Application* CreateApplication();
} // namespace CEngine
