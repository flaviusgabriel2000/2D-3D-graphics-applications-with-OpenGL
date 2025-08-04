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

// Output value to fragment shader
out vec3 color;
out vec3 world_position;
out vec3 world_normal;


void main()
{
    world_position = (Model * vec4(v_position, 1)).xyz;
    world_normal = normalize(mat3(Model) * normalize(v_normal));

    if (object_color.x == 1 && object_color.y == 1 && object_color.z == 1) {
        color = v_color;
    } else {
        color = object_color;
    }

    gl_Position = Projection * View * Model * vec4(v_position, 1.0f);
}
