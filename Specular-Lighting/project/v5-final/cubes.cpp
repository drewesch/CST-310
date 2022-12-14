#include "glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Camera.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(3.0f, 0.0f, 10.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	
float lastFrame = 0.0f;

// lighting
glm::vec3 lightPos[] = {
    glm::vec3(0.0f, 0.0f, 1.5f),
    glm::vec3(2.0f, 0.0f, 1.5f),
    glm::vec3(4.0f, 0.0f, 1.5f),
    glm::vec3(6.0f, 0.0f, 1.5f),
    glm::vec3(0.0f, -2.0f, 1.5f),
    glm::vec3(2.0f, -2.0f, 1.5f),
    glm::vec3(4.0f, -2.0f, 1.5f),
    glm::vec3(6.0f, -2.0f, 1.5f),
};

GLint shinyVals[8] = {2, 4, 8, 16, 32, 64, 128, 256};
    
int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader lightingShader("2.2.basic_lighting.vs", "2.2.basic_lighting.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    int x = 0;
    float vertices1[] = {
            -0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

            -0.5f + x,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f + x,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
        };

    x += 2;
    float vertices2[] = {
            -0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

            -0.5f + x,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f + x,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
        };

    x += 2;
    float vertices3[] = {
            -0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

            -0.5f + x,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f + x,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
        };
    
    x += 2;
    float vertices4[] = {
            -0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

            -0.5f + x,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f + x,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
        };

    //SECOND ROW ---------------------------------------------------------------
    x = 0;
    int y = -2;
    float vertices5[] = {
            -0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,

            -0.5f + x,  0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f + x,  0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f
        };

    x += 2;
    float vertices6[] = {
            -0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,

            -0.5f + x,  0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f + x,  0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f
        };

    x += 2;
    float vertices7[] = {
            -0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,

            -0.5f + x,  0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f + x,  0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f
        };
    
    x += 2;
    float vertices8[] = {
            -0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f + x, -0.5f + y, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x,  0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f + x, -0.5f + y,  0.5f,  0.0f,  0.0f,  1.0f,

            -0.5f + x,  0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x, -0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f + x,  0.5f + y,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f + x,  0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f + y,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f + x, -0.5f + y, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f + y,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f + x,  0.5f + y, -0.5f,  0.0f,  1.0f,  0.0f
        };

    //------------------------------------------------------------------------------------------------------    
    // first, configure the cube's VAO (and VBO)
    unsigned int VBO, cubeVAO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

//------------------------------------------------------------------------------------------------------

    // first, configure the cube's VAO (and VBO)
    unsigned int cubeVAO2;
    glGenVertexArrays(1, &cubeVAO2);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO2);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

//------------------------------------------------------------------------------------------------------

    // first, configure the cube's VAO (and VBO)
    unsigned int cubeVAO3;
    glGenVertexArrays(1, &cubeVAO3);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO3);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

//------------------------------------------------------------------------------------------------------

    // first, configure the cube's VAO (and VBO)
    unsigned int cubeVAO4;
    glGenVertexArrays(1, &cubeVAO4);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices4), vertices4, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO4);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //------------------------------------------------------------------------------------------------------    
    // first, configure the cube's VAO (and VBO)
    unsigned int cubeVAO5;
    glGenVertexArrays(1, &cubeVAO5);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices5), vertices5, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO5);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

//------------------------------------------------------------------------------------------------------

    // first, configure the cube's VAO (and VBO)
    unsigned int cubeVAO6;
    glGenVertexArrays(1, &cubeVAO6);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices6), vertices6, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO6);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

//------------------------------------------------------------------------------------------------------

    // first, configure the cube's VAO (and VBO)
    unsigned int cubeVAO7;
    glGenVertexArrays(1, &cubeVAO7);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices7), vertices7, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO7);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

//------------------------------------------------------------------------------------------------------

    // first, configure the cube's VAO (and VBO)
    unsigned int cubeVAO8;
    glGenVertexArrays(1, &cubeVAO8);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices8), vertices8, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO8);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    unsigned int cubeVAOS[] = {cubeVAO, cubeVAO2, cubeVAO3, cubeVAO4, cubeVAO5, cubeVAO6, cubeVAO7, cubeVAO8};

//------------------------------------------------------------------------------------------------------
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // View/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        lightingShader.setMat4("projection", projection);
        lightingShader.setMat4("view", view);

        // World generation and lighting
        for (GLuint i = 0; i < 8; i++) {
            lightingShader.use();
            lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
            lightingShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
            lightingShader.setVec3("lightPos", lightPos[i]);
            lightingShader.setVec3("viewPos", camera.Position);
            lightingShader.setInt("shininess", shinyVals[i]);

            // world transformation
            glm::mat4 model = glm::mat4(1.0f);
            lightingShader.setMat4("model", model);
            glBindVertexArray(cubeVAOS[i]);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}