//
//  transformation.cpp
//  cpp_example
//
//  Created by pengsida on 2017/10/17.
//  Copyright © 2017年 pengsida. All rights reserved.
//

#include "transformation.hpp"

void hello_trans() {
    GLFWwindow* win_handle;
    init_win(win_handle);
    init_glew();
    init_viewpoint(win_handle);
    
    shader shader_prog("/Users/pengsida/Documents/stack_psd/c&cpp/cpp_example/cpp_example/cg/transformation.vs", "/Users/pengsida/Documents/stack_psd/c&cpp/cpp_example/cpp_example/cg/transformation.fs");
    GLuint vao, vbo, ebo;
    square_data(vao, vbo, ebo, 1);
    
    glm::mat4 trans;
    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    
    glfwSetKeyCallback(win_handle, key_callback);
    while (!glfwWindowShouldClose(win_handle)) {
        glfwPollEvents();
        set_background();
        
        glm::mat4 transform(1.0);
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        
        shader_prog.use();
        shader_prog.set_uniform("transform", transform);
        glBindVertexArray(vao);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        
        glfwSwapBuffers(win_handle);
    }
    
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    
    glfwTerminate();
}
