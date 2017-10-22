//
//  cube.cpp
//  cpp_example
//
//  Created by pengsida on 2017/10/22.
//  Copyright © 2017年 pengsida. All rights reserved.
//

#include "cube.hpp"


void __gen_cube_data_front_back(float top_left_x, float top_left_y, float top_left_z, float r, float* vertices, int from) {
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


void __gen_cube_data_left_right(float top_left_x, float top_left_y, float top_left_z, float r, float* vertices, int from) {
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y + r;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y + r;
    vertices[from++] = top_left_z - r;
    
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z - r;
    
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y + r;
    vertices[from++] = top_left_z - r;
}


void __gen_cube_data_up_down(float top_left_x, float top_left_y, float top_left_z, float r, float* vertices, int from) {
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z + r;
    
    vertices[from++] = top_left_x - r;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z + r;
    
    vertices[from++] = top_left_x;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x - r;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z;
    
    vertices[from++] = top_left_x - r;
    vertices[from++] = top_left_y;
    vertices[from++] = top_left_z + r;
}


void gen_cube_data_front_back(float top_left_x, float top_left_y, float top_left_z, float* vertices, int& from, int nr_rows, float step, float pixel) {
    float temp_top_left_x = top_left_x;
    float temp_top_left_y = top_left_y;
    float temp_top_left_z = -pixel;
    for (int i = 0; i < nr_rows; i++) {
        temp_top_left_x = top_left_x;
        for (int j = 0; j < nr_rows; j++) {
            __gen_cube_data_front_back(temp_top_left_x, temp_top_left_y, temp_top_left_z, step, vertices, from);
            temp_top_left_x += step;
            from += 18;
        }
        temp_top_left_y -= step;
    }
    
    temp_top_left_x = top_left_x;
    temp_top_left_y = top_left_y;
    temp_top_left_z = pixel;
    for (int i = 0; i < nr_rows; i++) {
        temp_top_left_x = top_left_x;
        for (int j = 0; j < nr_rows; j++) {
            __gen_cube_data_front_back(temp_top_left_x, temp_top_left_y, temp_top_left_z, step, vertices, from);
            temp_top_left_x += step;
            from += 18;
        }
        temp_top_left_y -= step;
    }
}


void gen_cube_data_up_down(float top_left_x, float top_left_y, float top_left_z, float* vertices, int& from, int nr_rows, float step, float pixel) {
    float temp_top_left_x = -pixel;
    float temp_top_left_y = top_left_y;
    float temp_top_left_z = -top_left_z;
    for (int i = 0; i < nr_rows; i++) {
        temp_top_left_y = top_left_y - step;
        for (int j = 0; j < nr_rows; j++) {
            __gen_cube_data_left_right(temp_top_left_x, temp_top_left_y, temp_top_left_z, step, vertices, from);
            temp_top_left_y -= step;
            from += 18;
        }
        temp_top_left_z -= step;
    }
    
    temp_top_left_x = pixel;
    temp_top_left_y = top_left_y;
    temp_top_left_z = -top_left_z;
    for (int i = 0; i < nr_rows; i++) {
        temp_top_left_y = top_left_y - step;
        for (int j = 0; j < nr_rows; j++) {
            __gen_cube_data_left_right(temp_top_left_x, temp_top_left_y, temp_top_left_z, step, vertices, from);
            temp_top_left_y -= step;
            from += 18;
        }
        temp_top_left_z -= step;
    }
}


void gen_cube_data_left_right(float top_left_x, float top_left_y, float top_left_z, float* vertices, int& from, int nr_rows, float step, float pixel) {
    float temp_top_left_x = -top_left_x;
    float temp_top_left_y = -pixel;
    float temp_top_left_z = top_left_z;
    for (int i = 0; i < nr_rows; i++) {
        temp_top_left_z = top_left_z;
        for (int j = 0; j < nr_rows; j++) {
            __gen_cube_data_up_down(temp_top_left_x, temp_top_left_y, temp_top_left_z, step, vertices, from);
            temp_top_left_z += step;
            from += 18;
        }
        temp_top_left_x -= step;
    }
    
    temp_top_left_x = -top_left_x;
    temp_top_left_y = pixel;
    temp_top_left_z = top_left_z;
    for (int i = 0; i < nr_rows; i++) {
        temp_top_left_z = top_left_z;
        for (int j = 0; j < nr_rows; j++) {
            __gen_cube_data_up_down(temp_top_left_x, temp_top_left_y, temp_top_left_z, step, vertices, from);
            temp_top_left_z += step;
            from += 18;
        }
        temp_top_left_x -= step;
    }
}


void cube2sphere(float* vertices, int from) {
    float x = vertices[from];
    float y = vertices[from + 1];
    float z = vertices[from + 2];
    
    float new_x = x * sqrtf(1.0f - (y * y / 2.0f) - (z * z / 2.0f) + (y * y * z * z / 3.0f));
    float new_y = y * sqrtf(1.0f - (z * z / 2.0f) - (x * x / 2.0f) + (z * z * x * x / 3.0f));
    float new_z = z * sqrtf(1.0f - (x * x / 2.0f) - (y * y / 2.0f) + (x * x * y * y / 3.0f));
    
    vertices[from] = new_x;
    vertices[from + 1] = new_y;
    vertices[from + 2] = new_z;
}


void cube_data(GLuint& vao, GLuint& vbo, GLuint& ebo, int nr_square) {
    if (sqrt(nr_square) - (int)sqrt(nr_square) != 0)
        exit(1);
    
    int nr_rows = (int)sqrt(nr_square);
    float step = 2.0f / (float)nr_rows;
    float pixel = 1.0f;
    float top_left_x = -pixel;
    float top_left_y = pixel;
    float top_left_z = -pixel;
    int size = 6 * 18 * nr_square;
    float* vertices = new float[size];
    int from = 0;
    
    gen_cube_data_front_back(top_left_x, top_left_y, top_left_z, vertices, from, nr_rows, step, pixel);
    gen_cube_data_left_right(top_left_x, top_left_y, top_left_z, vertices, from, nr_rows, step, pixel);
    gen_cube_data_up_down(top_left_x, top_left_y, top_left_z, vertices, from, nr_rows, step, pixel);
    
//    for (int i = 0; i < size; i = i + 3)
//        cube2sphere(vertices, i);
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    delete[] vertices;
}


void draw_cube(shader& shader_prog, GLuint& vao, int nr_points, float cube_or_sphere) {
    glm::mat4 model(1.0f);
    glm::mat4 view(1.0f);
    glm::mat4 projection(1.0f);
    glm::mat4 scale(1.0f);
    
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    scale = glm::scale(scale, glm::vec3(0.5f, 0.5f, 0.5f));
    
    shader_prog.use();
    shader_prog.set_uniform("model", model);
    shader_prog.set_uniform("view", view);
    shader_prog.set_uniform("projection", projection);
    shader_prog.set_uniform("cube_or_sphere", cube_or_sphere);
    shader_prog.set_uniform("scale", scale);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(vao);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, nr_points);
    glBindVertexArray(0);
}


void hello_cube() {
    GLFWwindow* win_handle;
    init_win(win_handle);
    init_glew();
    init_viewpoint(win_handle);
    
    shader shader_prog("/Users/pengsida/Documents/stack_psd/c&cpp/cpp_example/cpp_example/cg/cube.vs", "/Users/pengsida/Documents/stack_psd/c&cpp/cpp_example/cpp_example/cg/cube.fs");
    GLuint vao, vbo, ebo;
    
    int nr_square = 64;
    int nr_points = 6 * 6 * nr_square;
    cube_data(vao, vbo, ebo, nr_square);
    
    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(win_handle, key_callback);
    int times = 0;
    int expand_or_shrink = 1;
    float cube_or_sphere = 0.0;
    while (!glfwWindowShouldClose(win_handle)) {
        glfwPollEvents();
        
        set_background();
        draw_cube(shader_prog, vao, nr_points, cube_or_sphere);
        times++;
        
        if (expand_or_shrink)
            cube_or_sphere = cube_or_sphere + 0.01;
        else
            cube_or_sphere = cube_or_sphere - 0.01;
        
        if (times == 100) {
            times = 0;
            expand_or_shrink = 1 - expand_or_shrink;
        }
        
        glfwSwapBuffers(win_handle);
    }
    
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    
    glfwTerminate();
}
