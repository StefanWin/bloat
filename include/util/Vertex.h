#pragma once
#include <glm/glm.hpp>

struct Vertex
{
    Vertex() : position{}, color{}, normal{} {};
    Vertex(const glm::vec4 &pos, const glm::vec4 &col, const glm::vec3 &norm) : position{pos}, color{col}, normal{norm} {};

    glm::vec4 position;
    glm::vec4 color;
    glm::vec3 normal;
};
