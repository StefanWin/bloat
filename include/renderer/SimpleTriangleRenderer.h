#pragma once

#include <vector>
#include <array>
#include "util/Vertex.h"
#include "core/BaseRenderer.h"

class SimpleTriangleRenderer : public BaseRenderer
{
private:
    GLuint program_id;
    GLuint vertex_array_id;
    GLuint vertex_buffer;
    GLuint matrix_id;

    GLuint model_uniform;
    GLuint view_uniform;
    GLuint proj_uniform;

    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;

    std::vector<Vertex> vertices;
    std::array<GLuint,3> attribute_locations;

protected:
    void pre_render() override;
    void render() override;
    void post_render() override;
    void render_gui() override;
public:
    SimpleTriangleRenderer(/* args */);
    ~SimpleTriangleRenderer();
};
