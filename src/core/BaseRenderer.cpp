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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
}

BaseRenderer::~BaseRenderer()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}

void BaseRenderer::run()
{
    while (!glfwWindowShouldClose(window))
    {
        // render cylce
        pre_render();
        render();
        post_render();

        // imgui bullshit
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        render_gui();
        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}