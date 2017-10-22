//
//  shader.cpp
//  cpp_example
//
//  Created by pengsida on 2017/10/18.
//  Copyright © 2017年 pengsida. All rights reserved.
//

#include "shader.hpp"

shader::shader(const GLchar* ver_path, const GLchar* frag_path) {
    string ver_code;
    string fra_code;
    ifstream ver_sha_file;
    ifstream fra_sha_file;
    
    ver_sha_file.exceptions(ifstream::failbit | ifstream::badbit);
    fra_sha_file.exceptions(ifstream::failbit | ifstream::badbit);
    try {
        ver_sha_file.open(ver_path);
        fra_sha_file.open(frag_path);
        
        stringstream ver_sha_stream, fra_sha_stream;
        ver_sha_stream << ver_sha_file.rdbuf();
        fra_sha_stream << fra_sha_file.rdbuf();
        ver_sha_file.close();
        fra_sha_file.close();
        ver_code = ver_sha_stream.str();
        fra_code = fra_sha_stream.str();
    } catch(ifstream::failure e) {
        cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
    }
    
    const char* ver_sha_code = ver_code.c_str();
    const char* fra_sha_code = fra_code.c_str();
    compile_shader(ver_sha_code, fra_sha_code);
}

void shader::use() {
    glUseProgram(id);
}

void shader::set_uniform(const string& name, bool value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void shader::set_uniform(const string& name, int value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void shader::set_uniform(const string& name, float value) const {
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void shader::set_uniform(const string& name, const glm::mat4& value) const {
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void shader::set_uniform(const string& name, float v1, float v2, float v3, float v4) const {
    glUniform4f(glGetUniformLocation(id, name.c_str()), v1, v2, v3, v4);
}

GLuint shader::get_uniform(const string& name) const {
    return glGetUniformLocation(id, name.c_str());
}

void shader::compile_shader(const char* ver_sha_code, const char* fra_sha_code) {
    GLuint ver_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(ver_shader, 1, &ver_sha_code, NULL);
    glCompileShader(ver_shader);
    
    GLuint fra_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fra_shader, 1, &fra_sha_code, NULL);
    glCompileShader(fra_shader);
    
    id = glCreateProgram();
    glAttachShader(id, ver_shader);
    glAttachShader(id, fra_shader);
    glLinkProgram(id);
    
    glDeleteShader(ver_shader);
    glDeleteShader(fra_shader);
}
