#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

const char* vssource = "#version 330 core\n"
"layout(location=0) in vec3 inPosition;\n"
"void main() {\n"
"    gl_Position = vec4(inPosition, 1.0);\n"
"}\n";

const char* fssource = "#version 330 core\n"
"out vec4 fragColor;\n"
"void main() {\n"
"    fragColor = vec4(1.0f,0.0f,0.0f, 1.0f);\n"
"}\n";

// triangle cords.
// x,y,z cords of 3 points.
float vertices[] = {
    0.0f,0.5f,0.0f,
    -0.5f,0.0f,0.0f,
    0.5f,0.0f,0.0f
};

//Objects that holds IDs
unsigned int fragmentShader;
unsigned int vertexShader;
unsigned int shaderProgram;
unsigned int VBO;
unsigned int VAO;

int main(void)
{
    if (!glfwInit()) return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Window", NULL, NULL);
    if (window == NULL) {
        std::cout << "Window does not createded." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    shaderProgram = glCreateProgram();
    
    glShaderSource(vertexShader, 1, &vssource, NULL);
    glShaderSource(fragmentShader, 1, &fssource, NULL);    
    
    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);

    // generate arrays and buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.4f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    
    glfwDestroyWindow(window);
    glfwTerminate();
}
