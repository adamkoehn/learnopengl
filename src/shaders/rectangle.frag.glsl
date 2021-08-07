#version 460 core

in vec3 vertexColor;
in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D texSampler;

void main()
{
    FragColor = texture(texSampler, texCoord);
}
