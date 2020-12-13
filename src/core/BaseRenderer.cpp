#include "core/BaseRenderer.h"

BaseRenderer::BaseRenderer()
{
    if (!glfwInit())
    {
        throw std::runtime_error("failed to initialize glfw3");
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(1280, 720, "bloat", nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, BaseRenderer::base_key_callback);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)
    {
        throw std::runtime_error("failed to initialize glew");
    }
    glewExperimental = GL_TRUE;
}

BaseRenderer::~BaseRenderer()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void BaseRenderer::base_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    auto *base_renderer = reinterpret_cast<BaseRenderer *>(glfwGetWindowUserPointer(window));
    base_renderer->key_callback(key, scancode, action, mods);
}

void BaseRenderer::run()
{
    while (!glfwWindowShouldClose(window))
    {
        pre_render();
        render();
        post_render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}