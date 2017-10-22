#version 330 core

layout (location = 0) in vec3 a_pos;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float cube_or_sphere;
uniform mat4 scale;

vec3 cube2sphere(vec3 cube, float cube_or_sphere) {
    float x = cube.x;
    float y = cube.y;
    float z = cube.z;
    
    float new_x = x * sqrt(1.0f - (y * y / 2.0f) - (z * z / 2.0f) + (y * y * z * z / 3.0f));
    float new_y = y * sqrt(1.0f - (z * z / 2.0f) - (x * x / 2.0f) + (z * z * x * x / 3.0f));
    float new_z = z * sqrt(1.0f - (x * x / 2.0f) - (y * y / 2.0f) + (x * x * y * y / 3.0f));
    
    return vec3((2 * new_x - x) * cube_or_sphere + x, (2 * new_y - y) * cube_or_sphere + y, (2 * new_z - z) * cube_or_sphere + z);
}

void main() {
    vec3 sphere = cube2sphere(a_pos, cube_or_sphere);
    gl_Position = projection * view * model * scale * vec4(sphere, 1.0f);
}
