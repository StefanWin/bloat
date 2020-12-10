#include <stdexcept>
#include "WindowManager.h"

WindowManager::WindowManager(int w, int h, std::string window_title)
{
    if (!glfwInit())
    {
        throw std::runtime_error("failed to initialize glfw3");
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(w, h, window_title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(window);
}

WindowManager::~WindowManager()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}