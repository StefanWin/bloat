#version 330 core

in vec4 position;
in vec4 color;
in vec3 normal;

out vec4 fragColor;
out vec3 fragNormal;

uniform mat4 MVP;

void main()
{
    fragColor = color;
    gl_Position = position * MVP; 
}