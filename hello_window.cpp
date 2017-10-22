//
//  hello_window.cpp
//  cpp_example
//
//  Created by pengsida on 2017/10/16.
//  Copyright © 2017年 pengsida. All rights reserved.
//

#include "hello_window.h"

void init_win(GLFWwindow*& win_handle) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    win_handle = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (win_handle == nullptr) {
        glfwTerminate();
        throw "fail to create window";
    }
    glfwMakeContextCurrent(win_handle);
}

void init_glew() {
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        throw "fail to init glew";
}


void init_viewpoint(GLFWwindow* win_handle) {
    int width;
    int height;
    glfwGetFramebufferSize(win_handle, &width, &height);
    glViewport(0, 0, width, height);
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}


void set_background() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


void hello_win() {
    GLFWwindow* win_handle;
    init_win(win_handle);
    init_glew();
    glViewport(0, 0, 800, 600);
    
    glfwSetKeyCallback(win_handle, key_callback);
    while(!glfwWindowShouldClose(win_handle)) {
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(win_handle);
    }
    
    glfwTerminate();
}

GLenum glCheckError_(const char *file, int line)
{
    GLenum errorCode;
    while ((errorCode = glGetError()) != GL_NO_ERROR)
    {
        std::string error;
        switch (errorCode)
        {
            case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
            case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
            case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
            case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
            case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
            case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
        }
        std::cout << error << " | " << file << " (" << line << ")" << std::endl;
    }
    return errorCode;
}
