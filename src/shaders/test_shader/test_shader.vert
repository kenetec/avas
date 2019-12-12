#version 150

// auto set
uniform mat4 modelViewProjectionMatrix;

in vec4 position;

void main()
{
    vec4 pos = modelViewProjectionMatrix * position;
    gl_Position = pos;
}