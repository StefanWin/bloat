#pragma once

#include "core/BaseRenderer.h"

class ImageRendererNV : public BaseRenderer
{
private:
    /* data */
    GLuint texture = 0;
    int img_width = 0;
    int img_height = 0;
    int img_channels = 0;
protected:
    void pre_render() override;
    void render() override;
    void post_render() override;
    void render_gui() override;

public:
    ImageRendererNV(/* args */);
    ~ImageRendererNV();
};


