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
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "İLk Programım", NULL, NULL);

    if (window == NULL) {
        std::cout << "Pencere Olusturulamadi" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //create vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vssource, NULL);
    glCompileShader(vertexShader);

    //create fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fssource, NULL);
    glCompileShader(fragmentShader);

    //creating program and attaching shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGenVertexArrays(1, &VAO); //creating vertex array object
    glGenBuffers(1, &VBO); //creating vertex buffer object

    
    glBindVertexArray(VAO);//enabling vertex array
    glBindBuffer(GL_ARRAY_BUFFER, VBO);//enabling vertex buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //attaching point(or verticles) datas to vertex buffer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//attribute pointer ataching.
    glEnableVertexAttribArray(0);//enabling attribute

    glfwSwapInterval(1); // for vsync

    while (!glfwWindowShouldClose(window))
    {
        //clearing window with color
        glClearColor(0.0f, 0.4f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);//enabling program for window
        glBindVertexArray(VAO);//enabling vertex array object
        glDrawArrays(GL_TRIANGLES, 0, 3);//sendin draw command

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}
