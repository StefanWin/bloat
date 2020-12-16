#pragma once

#include <vector>
#include <array>
#include "util/Vertex.h"
#include "core/BaseRenderer.h"

class SimpleTriangleRenderer : public BaseRenderer
{
private:
    GLuint program_id = 0;
    GLuint vertex_array_id = 0;
    GLuint vertex_buffer = 0;

    GLuint model_uniform = 0;
    GLuint view_uniform = 0;
    GLuint proj_uniform = 0;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 proj = glm::mat4(1.0f);

    std::vector<Vertex> vertices;
    std::array<GLuint,3> attribute_locations{};

protected:
    void pre_render() override;
    void render() override;
    void post_render() override;
    void render_gui() override;
public:
    SimpleTriangleRenderer(/* args */);
    ~SimpleTriangleRenderer();
};
