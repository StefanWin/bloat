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

    std::vector<Vertex> vertices;
    std::array<GLuint,3> attribute_locations;

protected:
    void pre_render() override;
    void render() override;
    void post_render() override;
    void key_callback(int key, int scancode, int action, int mods) override;

public:
    SimpleTriangleRenderer(/* args */);
    ~SimpleTriangleRenderer();
};
