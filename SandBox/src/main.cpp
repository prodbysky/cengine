#include "application.hpp"

#include <CEngine.hpp>

class SandBox : public CEngine::Application {
public:
    SandBox() {}
    ~SandBox() {}
};

CEngine::Application* CEngine::CreateApplication() { return new SandBox(); }
