#include "BaseRenderer.h"

BaseRenderer::BaseRenderer()
{
    window_manager = std::make_unique<WindowManager>(1280, 720, "bloat");
    if (glewInit() != GLEW_OK)
    {
        throw std::runtime_error("failed to initialize glew");
    }
    glewExperimental = GL_TRUE;
}

BaseRenderer::~BaseRenderer()
{
    window_manager = nullptr;
}

void BaseRenderer::run()
{
    while (!glfwWindowShouldClose(window_manager->window))
    {
        pre_render();
        render();
        post_render();
        glfwSwapBuffers(window_manager->window);
        glfwPollEvents();
    }
}