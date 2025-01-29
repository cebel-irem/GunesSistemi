#version 430
in vec3 outColor;
in vec3 outNorm;
in vec2 outTexCoord;

out vec4 fragColor;

uniform sampler2D texture1;

void main() {
   fragColor = texture(texture1, outTexCoord);
}

