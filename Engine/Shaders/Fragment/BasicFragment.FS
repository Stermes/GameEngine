#version 400 core
out vec4 FragColour;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D diffuse;

void main()
{
	FragColour = texture(diffuse, TexCoord) * vec4(ourColor, 1.0f);
}