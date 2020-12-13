#pragma once

#include "BaseRenderer.h"

class SimpleTriangleRenderer : public BaseRenderer
{
private:
    GLuint program_id;
    GLuint vertex_array_id;
    GLuint vertex_buffer;

protected:
    void pre_render() override;
    void render() override;
    void post_render() override;

public:
    SimpleTriangleRenderer(/* args */);
    ~SimpleTriangleRenderer();
};
