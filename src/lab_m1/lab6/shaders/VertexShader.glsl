#version 330

// Input
// TODO(student): Get vertex attributes from each location
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_text_coord;
layout(location = 3) in vec3 v_color;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform float ElapsedTime;

// Output
// TODO(student): Output values to fragment shader
out vec3 fragment_position;
out vec3 fragment_normal;
out vec2 fragment_text_coord;
out vec3 fragment_color;

void main()
{
    // TODO(student): Send output to fragment shader
    fragment_position = v_position;
    fragment_normal = v_normal;
    fragment_text_coord = v_text_coord;
    fragment_color = sin(ElapsedTime) * v_color;

    // TODO(student): Compute gl_Position
    gl_Position = Projection * View * Model * vec4(v_position + sin(ElapsedTime), 1.0);

}
