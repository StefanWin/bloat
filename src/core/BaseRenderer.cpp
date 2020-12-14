#include "core/BaseRenderer.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

BaseRenderer::BaseRenderer()
{
    if (!glfwInit())
    {
        throw std::runtime_error("failed to initialize glfw3");
    }
    window = glfwCreateWindow(1280, 720, "bloat", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
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