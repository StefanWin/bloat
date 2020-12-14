#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>

class BaseRenderer
{
protected:
    GLFWwindow *window;
    virtual void pre_render() = 0;
    virtual void render() = 0;
    virtual void post_render() = 0;
public:
    BaseRenderer(/* args */);
    ~BaseRenderer();
    void run();
};
