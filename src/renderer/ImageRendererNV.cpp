#include "renderer/ImageRendererNV.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <imgui.h>

ImageRendererNV::ImageRendererNV(/* args */)
{
    stbi_set_flip_vertically_on_load(1);
    auto data = stbi_load("resources/images/img.jpg", &img_width, &img_height, &img_channels, STBI_rgb_alpha);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        img_width,
        img_height,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}

ImageRendererNV::~ImageRendererNV()
{
    glDeleteTextures(1, &texture);
}

void ImageRendererNV::pre_render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, texture);
}

void ImageRendererNV::render()
{
    glActiveTexture(GL_TEXTURE0);
    glDrawTextureNV(texture, 0,
                    0, 0,
                    img_width, img_height,
                    1,
                    0, 0,
                    1, 1);
}

void ImageRendererNV::post_render()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void ImageRendererNV::render_gui()
{
    ImGui::Begin("ImageRendererNV");
    ImGui::Text("Image Dimensions: %dx%d", img_width, img_height);
    ImGui::End();
}