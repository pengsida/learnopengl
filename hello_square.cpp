//
//  hello_square.cpp
//  cpp_example
//
//  Created by pengsida on 2017/10/16.
//  Copyright © 2017年 pengsida. All rights reserved.
//

#include "hello_square.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>


void generate_data(float top_left_x, float top_left_y, float top_left_z, float r, float* vertices, int from) {
    float top_right_x, top_right_y, top_right_z;
    float bot_right_x, bot_right_y, bot_right_z;
    float bot_left_x, bot_left_y, bot_left_z;
    
    top_right_x = top_left_x + r;
    top_right_y = top_left_y;
    top_right_z = top_left_z;
    
    bot_right_x = top_left_x + r;
    bot_right_y = top_left_y - r;
    bot_right_z = top_left_z;
    
    bot_left_x = top_left_x;
    bot_left_y = top_left_y - r;
    bot_left_z = top_left_z;
    
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x + r;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x + r;
    vertices[from++] = top_left_y - r;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y - r;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x + r;
    vertices[from++] = top_left_y - r;
    vertices[from++] = top_left_z;
}


void square_data(GLuint& vao, GLuint& vbo, GLuint& ebo, int nr_square) {
//    float vertices[] = {
//        -0.5f,  0.5f, 0.0f,   // top left
//        0.5f,  0.5f, 0.0f,  // top right
//        0.5f, -0.5f, 0.0f,  // bottom right
//        -0.5f,  0.5f, 0.0f,   // top left
//        -0.5f, -0.5f, 0.0f,  // bottom left
//        0.5f, -0.5f, 0.0f  // bottom right
//    };
    
    if (sqrt(nr_square) - (int)sqrt(nr_square) != 0)
        exit(1);
    
    int nr_rows = (int)sqrt(nr_square);
    int nr_cols = nr_rows;
    float step = 1.0f / (float)nr_rows;
    float top_left_x = -0.5f;
    float top_left_y = 0.5f;
    float top_left_z = 0.0f;
    int size = 18 * nr_square;
    float* vertices = new float[size];
    int from = 0;
    
    for (int i = 0; i < nr_rows; i++) {
        float temp_top_left_x = top_left_x;
        for (int j = 0; j < nr_cols; j++) {
            generate_data(temp_top_left_x, top_left_y, top_left_z, step, vertices, from);
            temp_top_left_x += step;
            from += 18;
        }
        top_left_y -= step;
    }
    
    
//    float* test = new float[size];
//    generate_data(-0.5f, 0.5f, 0.0f, 0.5f, test, 0);
//    generate_data(0.0f, 0.5f, 0.0f, 0.5f, test, 18);
//    unsigned int indices[] = {
//        0, 1, 3,
//        1, 2, 3
//    };
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices, GL_STATIC_DRAW);
    
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
//    delete[] test;
    delete[] vertices;
}


void hello_square() {
    GLFWwindow* win_handle;
    init_win(win_handle);
    init_glew();
    init_viewpoint(win_handle);
    GLuint shader_prog = compile_shader();
    GLuint vao, vbo, ebo;
    
    int nr_square = 100;
    int nr_points = 6 * nr_square;
    square_data(vao, vbo, ebo, nr_square);
    
    glfwSetKeyCallback(win_handle, key_callback);
    while (!glfwWindowShouldClose(win_handle)) {
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shader_prog);
        glBindVertexArray(vao);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_TRIANGLES, 0, nr_points);
        glBindVertexArray(0);
        
        glfwSwapBuffers(win_handle);
    }
    
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    
    glfwTerminate();
}
