#version 150
uniform vec4 globalColor;
uniform float time;

out vec4 outputColor;

void main()
{
    vec3 color = globalColor.xyz;
    outputColor = vec4(color, 1.0);// * 0.1;
}