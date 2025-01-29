#version 430
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;

layout(location = 2) in vec3 aNormCoord;
layout(location = 3) in vec2 aTexCoord;


uniform mat4 translateMatrix;
uniform mat4 rotateMatrix;
uniform mat4 scaleMatrix;
uniform mat4 cameraMatrix;
uniform mat4 projectionMatrix;
out vec3 outColor;


out vec3 outNorm;
out vec2 outTexCoord;

void main() {
   gl_Position = projectionMatrix * cameraMatrix * translateMatrix * rotateMatrix * scaleMatrix *  vec4(position, 1.0);
   outColor = color;
   outNorm = aNormCoord;
   outTexCoord = aTexCoord;
}
