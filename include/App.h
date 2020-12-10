#pragma once
#include <GL/glew.h>
#include <memory>
#include "WindowManager.h"

class App
{
private:
    std::unique_ptr<WindowManager> window_manager;

    GLuint program_id;
    GLuint vertex_array_id;
    GLuint vertex_buffer;

public:
    App();
    ~App();
    void render();
};
