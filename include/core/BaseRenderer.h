#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>

class BaseRenderer
{
private:
    static void base_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

protected:
    GLFWwindow *window;
    virtual void pre_render() = 0;
    virtual void render() = 0;
    virtual void post_render() = 0;
    virtual void key_callback(int key, int scancode, int action, int mods) = 0;

public:
    BaseRenderer(/* args */);
    ~BaseRenderer();
    void run();
};
