//
//  hello_triangle.h
//  cpp_example
//
//  Created by pengsida on 2017/10/15.
//  Copyright © 2017年 pengsida. All rights reserved.
//

#ifndef hello_triangle_h
#define hello_triangle_h

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void vertex_input();

GLuint compile_shader();

void tri_data(GLuint& vao, GLuint& vbo);

void link_vertex_attr();

void hello_tri();

#endif /* hello_triangle_h */
