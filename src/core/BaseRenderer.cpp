#include "core/BaseRenderer.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <chrono>
#include <thread>

BaseRenderer::BaseRenderer()
{
    if (!glfwInit())
    {
        throw std::runtime_error("failed to initialize glfw3");
    }
    window = glfwCreateWindow(window_width, window_height, "bloat", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);
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
        auto render_start = std::chrono::high_resolution_clock::now();
        pre_render();
        render();
        post_render();
        auto render_end = std::chrono::high_resolution_clock::now();
        render_time = std::chrono::duration_cast<std::chrono::milliseconds>(render_end - render_start).count();
        // imgui bullshit
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        render_stats_window();
        render_gui();
        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
        auto cycle_end = std::chrono::high_resolution_clock::now();
        auto cycle_dur = std::chrono::duration_cast<std::chrono::milliseconds>(cycle_end - render_start).count();
        if (lock_fps)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(int64_t(1000.0f / fps_target) - cycle_dur));
        }
        auto pipeline_end = std::chrono::high_resolution_clock::now();
        pipeline_time = std::chrono::duration_cast<std::chrono::milliseconds>(pipeline_end - render_start).count();
    }
}

void BaseRenderer::render_stats_window()
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin("Stats", &display_stats_window, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("FPS"))
        {
            if (ImGui::MenuItem("30"))
            {
                fps_target = 30;
            }
            if (ImGui::MenuItem("60"))
            {
                fps_target = 90;
            }
            if (ImGui::MenuItem("120"))
            {
                fps_target = 120;
            }
            if (ImGui::MenuItem("144"))
            {
                fps_target = 144;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    ImGui::Checkbox("Lock FPS", &lock_fps);
    ImGui::Text("Render Time : %ld", render_time);
    ImGui::Text("Last Pipeline Time : %ld", pipeline_time);
    ImGui::Text("ImGui Render Time: %.3f ms/frame", 1000.0f / ImGui::GetIO().Framerate);
    ImGui::Text("ImGui FPS: %.1f FPS", ImGui::GetIO().Framerate);
    ImGui::End();
}