#pragma once

#include "application.hpp"
#include "log.hpp"

extern CEngine::Application* CEngine::CreateApplication();

int main(int argc, char** argv) {
    CEngine::Log::Init();
    CEngine::Application* app = CEngine::CreateApplication();
    app->Run();
    delete app;
}
