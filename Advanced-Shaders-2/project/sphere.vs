#version 330 core
layout (location = 0) in vec3 aPos; // Receives aPos
// layout (location = 1) in vec3 aNormal; // Receives aNormal
layout (location = 1) in vec2 texCoord; // Receives aNormal

out vec3 FragPos; // Returns FragPos
// out vec3 Normal; // Returns Normal
out vec2 TexCoord;

uniform mat4 model; // Receives model uniform
uniform mat4 view; // Receives view uniform
uniform mat4 projection; // Receives projection uniform

void main() {
    gl_Position = projection * view * vec4(aPos, 1.0f);  // Implements transformations - multiplies transformation vectors
    FragPos = vec3(model * vec4(aPos, 1.0));  // Sets fragment position
    // Normal = mat3(transpose(inverse(model))) * aNormal;  // Normalizes
    // vec2 mult= (2.0*texCoord - 1.0)/(2.0)
    // TexCoord = texture2D(vec2(texCoord.x, texCoord.y), mult);
    TexCoord = vec2(texCoord.x, texCoord.y);
}
