//
//  shader.hpp
//  cpp_example
//
//  Created by pengsida on 2017/10/18.
//  Copyright © 2017年 pengsida. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class shader {
public:
    GLuint id;
    
    shader(const GLchar* ver_path, const GLchar* fra_path);
    
    void use();
    
    void set_uniform(const string& name, bool value) const;
    void set_uniform(const string& name, int value) const;
    void set_uniform(const string& name, float vlaue) const;
    void set_uniform(const string& name, const glm::mat4& value) const;
    
    void set_uniform(const string& name, float v1, float v2, float v3, float v4) const;
    
    GLuint get_uniform(const string& name) const;
    
private:
    void compile_shader(const char* ver_sha_code, const char* fra_sha_code);
};


#endif /* shader_hpp */
