#pragma once

#include "application.hpp"

extern CEngine::Application* CEngine::CreateApplication();

int main(int argc, char** argv) {
    CEngine::Application* app = CEngine::CreateApplication();
    app->Run();
    delete app;
}
