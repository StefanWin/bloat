#pragma once
#include <GL/glew.h>
#include <memory>
#include "core/WindowManager.h"

class BaseRenderer
{
protected:
    std::unique_ptr<WindowManager> window_manager;
    virtual void pre_render() = 0;
    virtual void render() = 0;
    virtual void post_render() = 0;
public:
    BaseRenderer(/* args */);
    ~BaseRenderer();

    void run();
};

