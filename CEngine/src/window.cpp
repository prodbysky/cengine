#include <GLFW/glfw3.h>
#include <core.hpp>
#include <events/key_event.hpp>
#include <events/mouse_event.hpp>
#include <events/window_event.hpp>
#include <log.hpp>
#include <window.hpp>

namespace CEngine {

    static void GLFWErrorCallback(int error, const char* desc) {
        CE_ERROR << "GLFW error (" << error << ")" << ": " << desc;
    }

    Window::Window(const WindowConfig& config) {
        data.width  = config.width;
        data.height = config.height;
        data.title  = config.title;
        data.vsync  = config.vsync;

        CE_INFO << "Creating window: " << data.title << ", (" << data.width
                << ", " << data.height << ")";

        int success = glfwInit();
        CE_ASSERT(success, "Failed to initialize GLFW!")

        glfwSetErrorCallback(GLFWErrorCallback);

        window = glfwCreateWindow((int) data.width, (int) data.height,
                                  data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, &data);
        SetVSync(data.vsync);

        glfwSetWindowSizeCallback(
            window, [](GLFWwindow* window, int width, int height) {
                Data* data = (Data*) glfwGetWindowUserPointer(window);

                WindowResizeEvent event(width, height);
                data->width  = width;
                data->height = height;
                data->event_callback(event);
            });

        glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
            Data* data = (Data*) glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            data->event_callback(event);
        });

        glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode,
                                      int action, int mods) {
            (void) mods, (void) scancode;

            Data* data = (Data*) glfwGetWindowUserPointer(window);

            switch (action) {
            case GLFW_PRESS: {
                KeyPressedEvent event(key, 0);
                data->event_callback(event);
                break;
            }
            case GLFW_RELEASE: {
                KeyReleasedEvent event(key);
                data->event_callback(event);
                break;
            }
            case GLFW_REPEAT: {
                KeyPressedEvent event(key, 1);
                data->event_callback(event);
                break;
            }
            }
        });

        glfwSetMouseButtonCallback(
            window, [](GLFWwindow* window, int button, int action, int mods) {
                (void) mods;

                Data* data = (Data*) glfwGetWindowUserPointer(window);

                switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data->event_callback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data->event_callback(event);
                    break;
                }
                }
            });

        glfwSetScrollCallback(
            window, [](GLFWwindow* window, double x, double y) {
                Data* data = (Data*) glfwGetWindowUserPointer(window);
                MouseScrollEvent event(x, y);
                data->event_callback(event);
            });

        glfwSetCursorPosCallback(
            window, [](GLFWwindow* window, double x, double y) {
                Data* data = (Data*) glfwGetWindowUserPointer(window);
                MouseMovedEvent event(x, y);
                data->event_callback(event);
            });
    }

    Window::~Window() { glfwDestroyWindow(window); }

    void Window::Update() {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    unsigned int Window::GetWidth() const { return data.width; }
    unsigned int Window::GetHeight() const { return data.height; }

    void Window::SetEventCallback(const EventCallbackFunc& callback) {
        data.event_callback = callback;
    }

    void Window::SetVSync(bool enable) {
        data.vsync = enable;
        glfwSwapInterval(enable);
    }

    bool Window::IsVSync() { return data.vsync; }

} // namespace CEngine
