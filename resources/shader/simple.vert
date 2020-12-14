#version 330 core

in vec4 position;
in vec4 color;
in vec3 normal;

out vec4 fragColor;
out vec3 fragNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    mat4 mvp = proj * view * model;
    fragColor = color;
    gl_Position = mvp * position; 
}