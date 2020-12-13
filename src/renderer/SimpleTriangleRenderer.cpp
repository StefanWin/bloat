#include "renderer/SimpleTriangleRenderer.h"
#include "util/Shader.h"

SimpleTriangleRenderer::SimpleTriangleRenderer()
{
    program_id = load_shaders("resources/shader/simple.vert", "resources/shader/simple.frag");

    glGenVertexArrays(1, &vertex_array_id);
    glBindVertexArray(vertex_array_id);

    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f,
        -1.0f,
        0.0f,
        1.0f,
        -1.0f,
        0.0f,
        0.0f,
        1.0f,
        0.0f,
    };
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

SimpleTriangleRenderer::~SimpleTriangleRenderer()
{
    glDeleteBuffers(1, &vertex_buffer);
    glDeleteVertexArrays(1, &vertex_array_id);
    glDeleteProgram(program_id);
}

void SimpleTriangleRenderer::pre_render()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void SimpleTriangleRenderer::render()
{
    glUseProgram(program_id);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void *)0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void SimpleTriangleRenderer::post_render()
{
    glDisableVertexAttribArray(0);
}

void SimpleTriangleRenderer::key_callback(int key, int scancode, int action, int mods)
{
}