#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
class BaseRenderer
{

private:
    void render_stats_window();

    bool lock_fps = true;
    int64_t render_time;
    int64_t pipeline_time;
    uint8_t fps_target = 60;

protected:
    GLFWwindow *window;
    int window_width = 1280;
    int window_height = 720;

    virtual void pre_render() = 0;
    virtual void render() = 0;
    virtual void post_render() = 0;
    virtual void render_gui() = 0;

    bool display_stats_window = true;

public:
    BaseRenderer(/* args */);
    ~BaseRenderer();
    void run();
};
