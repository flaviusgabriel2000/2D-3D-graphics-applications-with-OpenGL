#version 330

// Input
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texture_coord;
layout(location = 3) in vec3 v_color;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

uniform vec3 object_color;
uniform vec3 Pcar;

// Output value to fragment shader
out vec3 color;


void main()
{
    if (object_color.x == 1 && object_color.y == 1 && object_color.z == 1) {
        color = v_color;
    } else {
        color = object_color;
    }
    
    vec3 world_pos = (Model * vec4(v_position, 1)).xyz;

    float dist = length(world_pos - Pcar), scaleFactor = 0.03f;
    dist = dist * dist;
    world_pos.y -= dist * scaleFactor;

    gl_Position = Projection * View * vec4(world_pos, 1.0f);
}
