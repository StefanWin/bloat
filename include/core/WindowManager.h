#pragma once

#include <GLFW/glfw3.h>
#include <string>

class WindowManager
{
private:
public:
    GLFWwindow *window;

    WindowManager(int w, int, std::string window_title);
    ~WindowManager();
};
