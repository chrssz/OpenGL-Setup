#include <iostream>

#include <EBO.h>
#include <VBO.h>
#include <VAO.h>
#include <shaderClass.h>

#include<glfw3.h>
#include<glad.h>
using namespace std; 


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    GLFWwindow* window;
    /* Initialize glfw library */
    if(!glfwInit())
    {
    
        return -1;
    }
    /*Create a windowed mode window and its OpenGL Context*/
    window = glfwCreateWindow(640,640,"Physics Simulation", NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    /* Load Glad */
    if (!gladLoadGL())
    {
        
        return -1;
    }
    /*
        leftMost = (-0.5,0); rightMost=(0.5,0); top(0,0.5);
    */

    GLfloat vertices[] = 
    { 
        -0.5f, -0.5f,  // Bottom-left
        0.5f, -0.5f,  // Bottom-right
        0.5f,  0.5f,  // Top-right
        -0.5f,  0.5f,   // Top-left


    };
    /*Index buffer */
    GLuint indices[] = 
    {
        0,1,2,
        2,3,0
        
    };
    
    glViewport(0,0,800,800);
    
    Shader shaderProgram;
    VAO VAO;
    EBO EBO(indices, sizeof(indices));
    VBO VBO(vertices, sizeof(vertices));   
    
    VAO.Bind();
    EBO.Bind();
    VAO.LinkVBO(VBO, 0);
   
    VAO.Unbind();
    while(!glfwWindowShouldClose(window))
    {
        /*Render here */
        glClearColor(0.05f,0.05f,0.15f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shaderProgram.Activate();
        EBO.Bind();
        VAO.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        /* Swap front and back buffers*/
        glfwSwapBuffers(window);
        /*Handles events*/
        glfwPollEvents();
        
    }
    shaderProgram.Delete();
    VBO.Delete();
    VAO.Delete();
    EBO.Bind();
    
    glfwTerminate();
    return 0;
}