//
//  hello_triangle.cpp
//  cpp_example
//
//  Created by pengsida on 2017/10/16.
//  Copyright © 2017年 pengsida. All rights reserved.
//

#include "hello_triangle.h"
#include "hello_window.h"

const GLchar* vertextShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"void main() {\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}";

const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main() {\n"
"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}";


GLuint compile_shader() {
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

void tri_data(GLuint& vao, GLuint& vbo) {
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        1.0f, 1.0f, 1.0f
    };
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    
    // 绑定vao，设定属性
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    // 设定属性之后可以解绑
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void link_vertex_attr() {
    GLFWwindow* win_handle;
    init_win(win_handle);
    init_glew();
    
    int width;
    int height;
    glfwGetFramebufferSize(win_handle, &width, &height);
    glViewport(0, 0, width, height);
    
    GLuint shader_prog = compile_shader();
    
    GLuint vao;
    GLuint vbo;
    tri_data(vao, vbo);
    
    glfwSetKeyCallback(win_handle, key_callback);
    while (!glfwWindowShouldClose(win_handle)) {
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shader_prog);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        
        glfwSwapBuffers(win_handle);
    }
    
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    
    glfwTerminate();
}

void hello_tri() {
    link_vertex_attr();
}
