#version 330 core
out vec4 FragColor; // Returns FragColor

in vec3 Normal; // Receives Normal
in vec3 FragPos; // Receives FragPos
in vec2 TexCoord;
  
uniform vec3 lightPos; // Receives lightPos uniform
uniform vec3 viewPos; // Receives viewPos uniform
uniform vec3 lightColor; // Recieves lightColor uniform
uniform vec3 cylinderColor; // Receives cylinderColor uniform

uniform sampler2D ourTexture;

void main() {
    // // ambient
    // float ambientStrength = 0.2; // Set ambient strength
    // vec3 ambient = ambientStrength * lightColor; // Sets ambient
    
    // // diffuse
    // vec3 norm = normalize(Normal); // Normalizes normal
    // vec3 lightDir = normalize(lightPos - FragPos); // Gets lightDir
    // float diff = max(dot(norm, lightDir), 0.0); // Gets diff
    // vec3 diffuse = 1.25 * diff * lightColor; // Sets diffuse

    // // specular
    // float specularStrength = 0.9f; // Sets specularStrength
    // vec3 viewDir = normalize(viewPos - FragPos); // Get viewDir
    // vec3 reflectDir = reflect(-lightDir, norm); // Get reflectDir
    // float spec = pow(max(dot(viewDir, reflectDir), 0.0), 256); // Get spec
    // vec3 specular = specularStrength * spec * lightColor; // Set specular

    // vec3 result = (ambient + diffuse + specular) * sphereColor; // Calculate result
    // FragColor = vec4(result, 1.0f); // Set FragColor output
    FragColor = texture(ourTexture, TexCoord);  // Sets vec4 based on result
}