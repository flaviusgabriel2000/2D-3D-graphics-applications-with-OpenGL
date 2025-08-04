#version 330

// Input
in vec3 color;
in vec3 world_position;
in vec3 world_normal;

uniform vec3 spot_light_pos[20];
uniform vec3 point_light_pos[15];
uniform vec3 pointLightColors[15];
uniform vec3 light_direction;
uniform vec3 eye_position;

uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

// Output
layout(location = 0) out vec4 out_color;

void main()
{
    vec3 N = normalize(world_normal);
    vec3 L = normalize(-light_direction);
    vec3 V = normalize(eye_position - world_position);
    vec3 H = normalize(L + V);

    float ambient_light = material_kd * 0.25f;
    float diffuse_light = material_kd * max(dot(N, L), 0);
    float specular_light = 0;

    if (diffuse_light > 0) {
        specular_light = material_ks * pow(max(dot(N, H), 0), material_shininess);
    }
    float directionalLight = ambient_light + diffuse_light + specular_light;

    float spotLights[20];
    vec3 pointLights[15];
    int i;

    for (i = 0; i < 15; i++) {
        if (point_light_pos[i].x == 0 && point_light_pos[i].y == 0 && point_light_pos[i].z == 0) {
            pointLights[i] = vec3(0, 0, 0);
            continue;
        }
        vec3 L = normalize(point_light_pos[i] - world_position);
        vec3 H = normalize(L + V);

        float distance = distance(point_light_pos[i], world_position);
        float attenuationFactor = 1 / (distance * distance);

        float ambient_light = material_kd * 0.1f;
        float diffuse_light = material_kd * max(dot(N, L), 0) * 0.25f;
        float specular_light = 0;

        if (diffuse_light > 0) {
            specular_light = material_ks * pow(max(dot(N, H), 0), material_shininess);
        }
        float pointLight = attenuationFactor * (ambient_light + diffuse_light + specular_light);
        pointLights[i] = pointLight * pointLightColors[i];
    }

    for (i = 0; i < 20; i++) {
        vec3 L = normalize(spot_light_pos[i] - world_position);
        vec3 H = normalize(L + V);

        float distance = distance(spot_light_pos[i], world_position);
        float attenuationFactor = 1 / (distance * distance);

        float cut_off = radians(60);
        float spot_light = dot(-L, light_direction);
        float spot_light_limit = cos(cut_off);
        float linear_att = (spot_light - spot_light_limit) / (1.0f - spot_light_limit);
        float light_att_factor = pow(linear_att, 2);

        float diffuse_light = material_kd * max(dot(N, L), 0);
        float specular_light = 0;

        if (diffuse_light > 0) {
            specular_light = material_ks * pow(max(dot(N, H), 0), material_shininess);
        }

        if (spot_light > cos(cut_off)) {
            spotLights[i] = light_att_factor * attenuationFactor * (diffuse_light + specular_light);
        }
        else {
            spotLights[i] = 0;  
        }
    }

    float spotLight = 0.0f;
    vec3 pointLight = vec3(0, 0, 0);

    for (i = 0; i < 20; i++) {
        spotLight += spotLights[i];
        if (i < 15) {
            pointLight += pointLights[i] * color;
        }
    }

    out_color = vec4((directionalLight + spotLight) * color, 1) + vec4(pointLight, 1);
}
