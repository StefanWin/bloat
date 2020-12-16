#include "renderer/SimpleTriangleRenderer.h"
#include "util/Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

SimpleTriangleRenderer::SimpleTriangleRenderer()
{
    program_id = load_shaders("resources/shader/simple.vert", "resources/shader/simple.frag");

    proj = glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);
    view = glm::lookAt(
        glm::vec3(0, 0, 5),
        glm::vec3(0, 0, 0),
        glm::vec3(0, 1, 0));
    model = glm::mat4(1.0f);

    model_uniform = glGetUniformLocation(program_id, "model");
    view_uniform = glGetUniformLocation(program_id, "view");
    proj_uniform = glGetUniformLocation(program_id, "proj");

    attribute_locations[0] = glGetAttribLocation(program_id, "position");
    attribute_locations[1] = glGetAttribLocation(program_id, "color");
    attribute_locations[2] = glGetAttribLocation(program_id, "normal");

    glGenVertexArrays(1, &vertex_array_id);
    glBindVertexArray(vertex_array_id);

    vertices.emplace_back(glm::vec4(-1.0f, -1.0f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    vertices.emplace_back(glm::vec4(1.0f, -1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    vertices.emplace_back(glm::vec4(-1.0f, 1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    vertices.emplace_back(glm::vec4(-1.0f, 1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    vertices.emplace_back(glm::vec4(1.0f, -1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    vertices.emplace_back(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), reinterpret_cast<GLvoid *>(vertices.data()), GL_STATIC_DRAW);

    glEnableVertexAttribArray(attribute_locations[0]);
    glVertexAttribPointer(attribute_locations[0], 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    glEnableVertexAttribArray(attribute_locations[1]);
    glVertexAttribPointer(attribute_locations[1], 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(sizeof(glm::vec4)));
    glEnableVertexAttribArray(attribute_locations[2]);
    glVertexAttribPointer(attribute_locations[2], 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(sizeof(glm::vec4) + sizeof(glm::vec4)));

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

SimpleTriangleRenderer::~SimpleTriangleRenderer()
{
    glDeleteBuffers(1, &vertex_buffer);
    glDeleteVertexArrays(1, &vertex_array_id);
    glDeleteProgram(program_id);
    vertices.clear();
}

void SimpleTriangleRenderer::pre_render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program_id);
    glUniformMatrix4fv(model_uniform, 1, GL_FALSE, &model[0][0]);
    glUniformMatrix4fv(view_uniform, 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(proj_uniform, 1, GL_FALSE, &proj[0][0]);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBindVertexArray(vertex_array_id);
}

void SimpleTriangleRenderer::render()
{
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}

void SimpleTriangleRenderer::post_render()
{
    glBindVertexArray(0);
    glUseProgram(0);
    model = glm::rotate(model, glm::radians(1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}

void SimpleTriangleRenderer::render_gui()
{
}