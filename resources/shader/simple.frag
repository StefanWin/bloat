#version 330 core

in vec4 fragColor;
in vec3 fragNormal;

out vec4 outColor;

void main()
{
	outColor = fragColor;
}