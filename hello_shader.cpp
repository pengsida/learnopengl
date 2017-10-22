//
//  hello_shader.cpp
//  cpp_example
//
//  Created by pengsida on 2017/10/16.
//  Copyright © 2017年 pengsida. All rights reserved.
//

#include "hello_shader.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void shader_data(GLuint& vao, GLuint& vbo, GLuint& ebo) {
    float vertices[] = {
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3,
        0, 1, 2
    };
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


GLuint square_shader() {
    const GLchar* vertextShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "layout (location = 1) in vec3 in_color;\n"
    "out vec3 out_color;\n"
    "void main() {\n"
    "gl_Position = vec4(position, 1.0);\n"
    "out_color = in_color;\n"
    "}";
    
    const GLchar* fragmentShaderSource = "#version 330 core\n"
    "in vec3 out_color;\n"
    "out vec4 color;\n"
    "void main() {\n"
    "color = vec4(out_color, 1.0f);\n"
    "}";
    
    GLuint vx_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vx_shader, 1, &vertextShaderSource, NULL);
    glCompileShader(vx_shader);
    
    GLuint fra_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fra_shader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fra_shader);
    
    GLuint shader_prog = glCreateProgram();
    glAttachShader(shader_prog, vx_shader);
    glAttachShader(shader_prog, fra_shader);
    glLinkProgram(shader_prog);
    
    glDeleteShader(vx_shader);
    glDeleteShader(fra_shader);
    
    return shader_prog;
}

void hello_shader() {
    GLFWwindow* win_handle;
    init_win(win_handle);
    init_glew();
    init_viewpoint(win_handle);
    GLuint shader_prog = square_shader();
    GLuint vao, vbo, ebo;
    shader_data(vao, vbo, ebo);
    
    glfwSetKeyCallback(win_handle, key_callback);
    while (!glfwWindowShouldClose(win_handle)) {
        glfwPollEvents();
        set_background();
        
        glUseProgram(shader_prog);
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        glfwSwapBuffers(win_handle);
    }
    
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    
    glfwTerminate();
}
