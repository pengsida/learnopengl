//
//  hello_window.h
//  cpp_example
//
//  Created by pengsida on 2017/10/15.
//  Copyright © 2017年 pengsida. All rights reserved.
//

#ifndef hello_window_h
#define hello_window_h

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void init_win(GLFWwindow*& win_handle);

void init_glew();

void init_viewpoint(GLFWwindow* win_handle);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

void set_background();

void hello_win();

GLenum glCheckError_(const char *file, int line);
#define glCheckError() glCheckError_(__FILE__, __LINE__)

#endif /* hello_window_h */
