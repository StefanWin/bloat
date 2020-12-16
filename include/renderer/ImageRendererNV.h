#pragma once

#include "core/BaseRenderer.h"

class ImageRendererNV : public BaseRenderer
{
private:
    /* data */
    GLuint texture;
    int img_width;
    int img_height;
    int img_channels;
protected:
    void pre_render() override;
    void render() override;
    void post_render() override;
    void render_gui() override;

public:
    ImageRendererNV(/* args */);
    ~ImageRendererNV();
};


