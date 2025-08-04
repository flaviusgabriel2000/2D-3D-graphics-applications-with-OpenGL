#include "lab_m1/Tema2/Tema2.h"
#include "lab_m1/lab4/transform3D.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}

void Tema2::CreateTree()
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(-0.3f, 0,  -0.3f), glm::vec3(51.0f / 255, 25.0f / 255, 0)),
        VertexFormat(glm::vec3(-0.3f, 0,  0.3f), glm::vec3(51.0f / 255, 25.0f / 255, 0)),
        VertexFormat(glm::vec3(0.3f, 0,  -0.3f), glm::vec3(51.0f / 255, 25.0f / 255, 0)),
        VertexFormat(glm::vec3(0.3f, 0,  0.3f), glm::vec3(51.0f / 255, 25.0f / 255, 0)),
        VertexFormat(glm::vec3(-0.3f, 1,  -0.3f), glm::vec3(51.0f / 255, 25.0f / 255, 0)),
        VertexFormat(glm::vec3(-0.3f, 1,  0.3f), glm::vec3(51.0f / 255, 25.0f / 255, 0)),
        VertexFormat(glm::vec3(0.3f, 1,  -0.3f), glm::vec3(51.0f / 255, 25.0f / 255, 0)),
        VertexFormat(glm::vec3(0.3f, 1,  0.3f), glm::vec3(51.0f / 255, 25.0f / 255, 0)),

        VertexFormat(glm::vec3(-0.7f, 1.02f,  -0.7f), glm::vec3(91.0f / 255, 128.0f / 255, 54.0f / 255)),
        VertexFormat(glm::vec3(-0.7f, 1.02f,  0.7f), glm::vec3(91.0f / 255, 128.0f / 255, 54.0f / 255)),
        VertexFormat(glm::vec3(0.7f, 1.02f,  -0.7f), glm::vec3(91.0f / 255, 128.0f / 255, 54.0f / 255)),
        VertexFormat(glm::vec3(0.7f, 1.02f,  0.7f), glm::vec3(91.0f / 255, 128.0f / 255, 54.0f / 255)),
        VertexFormat(glm::vec3(-0.7f, 2.8f,  -0.7f), glm::vec3(91.0f / 255, 128.0f / 255, 54.0f / 255)),
        VertexFormat(glm::vec3(-0.7f, 2.8f, 0.7f), glm::vec3(91.0f / 255, 128.0f / 255, 54.0f / 255)),
        VertexFormat(glm::vec3(0.7f, 2.8f,  -0.7f), glm::vec3(91.0f / 255, 128.0f / 255, 54.0f / 255)),
        VertexFormat(glm::vec3(0.7f, 2.8f,  0.7f), glm::vec3(91.0f / 255, 128.0f / 255, 54.0f / 255)),
    };

    vector<unsigned int> indices =
    {
        0, 1, 2,
        1, 3, 2,
        2, 3, 7,
        2, 7, 6,
        1, 7, 3,
        1, 5, 7,
        6, 7, 4,
        7, 5, 4,
        0, 4, 1,
        1, 4, 5,
        2, 6, 4,
        0, 2, 4,

        8, 9, 10,
        9, 11, 10,
        10, 11, 15,
        10, 15, 14,
        9, 15, 11,
        9, 13, 15,
        14, 15, 12,
        8, 12, 9,
        9, 12, 13,
        10, 14, 12,
        8, 10, 12
    };

    treesPositions.push_back(glm::ivec2(0, 1));
    treesPositions.push_back(glm::ivec2(2, 2));
    treesPositions.push_back(glm::ivec2(4, 3));
    treesPositions.push_back(glm::ivec2(6, 4));
    treesPositions.push_back(glm::ivec2(8, 4));
    treesPositions.push_back(glm::ivec2(10, 3));
    treesPositions.push_back(glm::ivec2(11, 1));
    treesPositions.push_back(glm::ivec2(11, -2));
    treesPositions.push_back(glm::ivec2(9, -2));
    treesPositions.push_back(glm::ivec2(7, -1));
    treesPositions.push_back(glm::ivec2(4, 0));
    treesPositions.push_back(glm::ivec2(1, -1));
    treesPositions.push_back(glm::ivec2(-2, -3));
    treesPositions.push_back(glm::ivec2(-4, -3));
    treesPositions.push_back(glm::ivec2(-7, -2));
    treesPositions.push_back(glm::ivec2(-9, 0));
    treesPositions.push_back(glm::ivec2(-8, 2));
    treesPositions.push_back(glm::ivec2(-6, 2));
    treesPositions.push_back(glm::ivec2(-3, 1));

    int size = treesPositions.size(), x, y;
    for (int i = 0; i < size; i++) {
        x = treesPositions[i].x;
        y = treesPositions[i].y;
        if (x >= 10 || x <= -9) {
            continue;
        }
        if (y > 0) {
            y += 5;
        }
        else {
            y -= 5;
        }
        treesPositions.push_back(glm::ivec2(x, y));
    }
    treesPositions.push_back(glm::ivec2(10, 8));
    treesPositions.push_back(glm::ivec2(14, 7));
    treesPositions.push_back(glm::ivec2(15, 4));
    treesPositions.push_back(glm::ivec2(16, 1));
    treesPositions.push_back(glm::ivec2(16, -3));
    treesPositions.push_back(glm::ivec2(12, -6));
    treesPositions.push_back(glm::ivec2(-7, -7));
    treesPositions.push_back(glm::ivec2(-12, -4));
    treesPositions.push_back(glm::ivec2(-13, -1));
    treesPositions.push_back(glm::ivec2(-13, 3));
    treesPositions.push_back(glm::ivec2(-10, 5));

    Mesh* tree = new Mesh("tree");
    tree->InitFromData(vertices, indices);
    AddMeshToList(tree);
}

void Tema2::CreateCar()
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(-0.5f, 0,  -1), glm::vec3(1, 0, 0)),
        VertexFormat(glm::vec3(-0.5f, 0,  1), glm::vec3(0, 1, 0)),
        VertexFormat(glm::vec3(0.5f, 0,  -1), glm::vec3(0, 0, 1)),
        VertexFormat(glm::vec3(0.5f, 0,  1),  glm::vec3(1, 0, 0)),
        VertexFormat(glm::vec3(-0.5f, 1,  -1), glm::vec3(0, 1, 0)),
        VertexFormat(glm::vec3(-0.5f, 1,  1), glm::vec3(0, 0, 1)),
        VertexFormat(glm::vec3(0.5f, 1,  -1), glm::vec3(1, 0, 0)),
        VertexFormat(glm::vec3(0.5f, 1,  1), glm::vec3(0, 1, 0)),
    };

    vector<unsigned int> indices =
    {
        0, 1, 2,
        1, 3, 2,
        2, 3, 7,
        2, 7, 6,
        1, 7, 3,
        1, 5, 7,
        6, 7, 4,
        7, 5, 4,
        0, 4, 1,
        1, 4, 5,
        2, 6, 4,
        0, 2, 4
    };

    Mesh* car = new Mesh("car");
    car->InitFromData(vertices, indices);
    AddMeshToList(car);
}

void Tema2::CreateTrack()
{
    float color = 32.0f / 255;
    float dist_inner = 0.56f;
    float dist_outer = 0.24f;

    std::vector<glm::vec3> path1, path2, path3;
    float dist_path2 = 0.21f, dist_path3 = 0.46f;
    trackVertices =
    {
        VertexFormat(glm::vec3(4.86f , 0, 0.29f), glm::vec3(color, color, color)), // A
        VertexFormat(glm::vec3(4.21f , 0, 1.4f), glm::vec3(color, color, color)), // B
        VertexFormat(glm::vec3(2.79f, 0, 2.14f), glm::vec3(color, color, color)), // C
        VertexFormat(glm::vec3(1.5f, 0, 1.95f), glm::vec3(color, color, color)), // D
        VertexFormat(glm::vec3(0.59f, 0, 1.25f), glm::vec3(color, color, color)), // E
        VertexFormat(glm::vec3(-0.48f, 0, 0.6f), glm::vec3(color, color, color)), // F
        VertexFormat(glm::vec3(-1.76f, 0, 1.15f), glm::vec3(color, color, color)), // G
        VertexFormat(glm::vec3(-2.83f, 0, 1.43f), glm::vec3(color, color, color)), // H
        VertexFormat(glm::vec3(-3.79f, 0, 0.81f), glm::vec3(color, color, color)), // I
        VertexFormat(glm::vec3(-3.93f, 0, -0.19f), glm::vec3(color, color, color)), // J
        VertexFormat(glm::vec3(-3.45f, 0, -1.05f), glm::vec3(color, color, color)), // K
        VertexFormat(glm::vec3(-2.11f, 0, -1.55f), glm::vec3(color, color, color)), // L
        VertexFormat(glm::vec3(-0.68f, 0, -1.62f), glm::vec3(color, color, color)), // M
        VertexFormat(glm::vec3(0.44f, 0, -0.98f), glm::vec3(color, color, color)), // N
        VertexFormat(glm::vec3(1.4f, 0, -0.45f), glm::vec3(color, color, color)), // O
        VertexFormat(glm::vec3(2.58f, 0, -0.76f), glm::vec3(color, color, color)), // P
        VertexFormat(glm::vec3(3.45f, 0, -1.42f), glm::vec3(color, color, color)), // Q
        VertexFormat(glm::vec3(4.57f, 0, -1.18f), glm::vec3(color, color, color)), // R
    };

    glm::vec3 P1, P2, D, P, UP = glm::vec3(0, 1, 0), inner, outer;
    std::vector<VertexFormat> tmp_inner_vertices, tmp_outer_vertices;
    for (int i = 0; i < trackVertices.size(); i++) {
        P1 = trackVertices[i % trackVertices.size()].position;
        P2 = trackVertices[(i + 1) % trackVertices.size()].position;
        D = P2 - P1;
        P = glm::cross(D, UP);
        outer = P1 - dist_inner * P;
        inner = P1 + dist_outer * P;
        tmp_outer_vertices.push_back(VertexFormat(outer, glm::vec3(color, color, color)));
        tmp_inner_vertices.push_back(VertexFormat(inner, glm::vec3(color, color, color)));
        outerVertices.push_back(outer);
        innerVertices.push_back(inner);

        // Enemy cars paths
        path1.push_back(P1);
        path2.push_back(P1 - dist_path2 * P);
        path3.push_back(P1 - dist_path3 * P);

        // Cars' directions need to be parallel with the track's segments
        glm::vec3 position = glm::normalize(trackVertices[(i + 1) % trackVertices.size()].position - trackVertices[i % trackVertices.size()].position);
        float angle = acos(glm::dot(glm::vec3(1, 0, 0), position));
        if (position.z > 0) { // Quadrant III and IV
            angle = -angle;
        }
        angles.push_back(angle);
    }
    Tema2::paths = { path1, path2, path3 };


    std::vector<VertexFormat> final_vertices;
    glm::vec3 position_outer, position_inner;
    float step_outer_x, step_outer_z, step_inner_x, step_inner_z;
    for (int i = 0; i < tmp_outer_vertices.size(); i++) {
        // Distance between two consecutive vertices on a segment of the track
        step_outer_x = (tmp_outer_vertices[(i + 1) % tmp_outer_vertices.size()].position.x - tmp_outer_vertices[i % tmp_outer_vertices.size()].position.x) / 10;
        step_outer_z = (tmp_outer_vertices[(i + 1) % tmp_outer_vertices.size()].position.z - tmp_outer_vertices[i % tmp_outer_vertices.size()].position.z) / 10;
        step_inner_x = (tmp_inner_vertices[(i + 1) % tmp_inner_vertices.size()].position.x - tmp_inner_vertices[i % tmp_inner_vertices.size()].position.x) / 10;
        step_inner_z = (tmp_inner_vertices[(i + 1) % tmp_inner_vertices.size()].position.z - tmp_inner_vertices[i % tmp_inner_vertices.size()].position.z) / 10;

        final_vertices.push_back(tmp_outer_vertices[i % tmp_outer_vertices.size()]);
        final_vertices.push_back(tmp_inner_vertices[i % tmp_inner_vertices.size()]);
        position_outer = tmp_outer_vertices[i % tmp_outer_vertices.size()].position;
        position_inner = tmp_inner_vertices[i % tmp_inner_vertices.size()].position;
        for (int j = 1; j <= 9; j++) {
            final_vertices.push_back(VertexFormat(glm::vec3(position_outer.x + j * step_outer_x, 0, position_outer.z + j * step_outer_z), glm::vec3(color, color, color)));
            final_vertices.push_back(VertexFormat(glm::vec3(position_inner.x + j * step_inner_x, 0, position_inner.z + j * step_inner_z), glm::vec3(color, color, color)));
        }
    }
    final_vertices[final_vertices.size() - 2] = final_vertices[0];
    final_vertices[final_vertices.size() - 1] = final_vertices[1];
    
    int i1 = 0, i2 = 1, i3 = 2, i4 = 3;
    std::vector<unsigned int> indices;
    for (int i = 1; i < final_vertices.size() / 2; i++) {
        indices.push_back(i1);
        indices.push_back(i2);
        indices.push_back(i4);
        indices.push_back(i1);
        indices.push_back(i4);
        indices.push_back(i3);
        i1 = i3;
        i2 = i4;
        i3 += 2;
        i4 += 2;
    }

    Mesh* track = new Mesh("track");
    track->SetDrawMode(GL_TRIANGLES);
    track->InitFromData(final_vertices, indices);
    AddMeshToList(track);
}

void Tema2::Init()
{
    orthoLeft = -10;
    orthoRight = 10;
    orthoBottom = -5;
    orthoTop = 5;
    zNearO = 1;
    zFarO = 11;

    fov = RADIANS(60);
    aspect = window->props.aspectRatio;
    zNearP = 0.01f;
    zFarP = 200.0f;

    carAngularStep = M_PI / 2;

    camera = new implemented::Camera();
    camera->Set(glm::vec3(0, 1.05f, 3.5f), glm::vec3(0, -0.8f, 0), glm::vec3(0, 1, 0));
    camera->RotateFirstPerson_OY(-M_PI / 2);

    minimapCamera = new implemented::Camera();
    minimapCamera->Set(glm::vec3(0, 1.05f, 3.5f), glm::vec3(0, -0.8f, 0), glm::vec3(0, 1, 0));
    minimapCamera->RotateFirstPerson_OY(-M_PI / 2);
    minimapCamera->RotateThirdPerson_OX(-1);

    perspectiveMatrix = glm::perspective(fov, aspect, zNearP, zFarP);
    orthoMatrix = glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop, zNearO, zFarO);
    projectionMatrix = perspectiveMatrix;
    glm::ivec2 resolution = window->GetResolution();
    minimapArea = ViewportArea(50, 50, resolution.x / 3.5f, resolution.y / 3.5f);

    Mesh* mesh = new Mesh("plane");
    mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "plane50.obj");
    meshes[mesh->GetMeshID()] = mesh;

    Shader* shader = new Shader("Tema2Shader");
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
    shader->CreateAndLink();
    shaders[shader->GetName()] = shader;

    CreateTrack();
    CreateTree();
    CreateCar();

    translateXCar_1 = paths[0][indexCar_1].x;
    translateZCar_1 = paths[0][indexCar_1].z;
    translateXCar_2 = paths[1][indexCar_2].x;
    translateZCar_2 = paths[1][indexCar_2].z;
    translateXCar_3 = paths[2][indexCar_3].x;
    translateZCar_3 = paths[2][indexCar_3].z;
}

Mesh* Tema2::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices)
{
    unsigned int VAO = 0;
    // Create the VAO and bind it
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Create the VBO and bind it
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Send vertices data into the VBO buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    // Create the IBO and bind it
    unsigned int IBO;
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    // Send indices data into the IBO buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

    // Set vertex position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

    // Set vertex normal attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

    // Set texture coordinate attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

    // Set vertex color attribute
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
    // ========================================================================

    // Unbind the VAO
    glBindVertexArray(0);

    // Check for OpenGL errors
    CheckOpenGLError();

    // Mesh information is saved into a Mesh object
    meshes[name] = new Mesh(name);
    meshes[name]->InitFromBuffer(VAO, static_cast<unsigned int>(indices.size()));
    meshes[name]->vertices = vertices;
    meshes[name]->indices = indices;
    return meshes[name];
}


void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::MoveCar(float &translateX, float &translateZ, int &index, std::vector<glm::vec3> &path, float deltaTimeSeconds)
{
    if (abs(translateX - path[(index + 1) % path.size()].x) < 0.1 && abs(translateZ - path[(index + 1) % path.size()].z < 0.1)) {
        index++;
        if (index == path.size()) {
            index = 0;
        }
    }
    if (translateX > path[(index + 1) % path.size()].x) {
        translateX -= abs(path[(index + 1) % path.size()].x - path[(index) % path.size()].x) * deltaTimeSeconds;
    }
    else if (translateX < path[(index + 1) % path.size()].x) {
        translateX += abs(path[(index + 1) % path.size()].x - path[(index) % path.size()].x) * deltaTimeSeconds;;
    }
    if (translateZ < path[(index + 1) % path.size()].z) {
        translateZ += abs(path[(index + 1) % path.size()].z - path[(index) % path.size()].z) * deltaTimeSeconds;
    }
    else if (translateZ > path[(index + 1) % path.size()].z) {
        translateZ -= abs(path[(index + 1) % path.size()].z - path[(index) % path.size()].z) * deltaTimeSeconds;
    }
}

void Tema2::RenderEnvironment(implemented::Camera *camera)
{   
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(0, 0.01f, 0);
    modelMatrix *= transform3D::Scale(2, 1, 2);
    RenderMesh(meshes["plane"], shaders["Tema2Shader"], modelMatrix, camera, glm::vec3(126.0f / 255, 180.0f / 255, 80.0f / 255));

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(0, 0.1f, 0);
    modelMatrix *= transform3D::Scale(2.75f, 1, 3);
    RenderMesh(meshes["track"], shaders["Tema2Shader"], modelMatrix, camera);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(0, 10, 0);
    modelMatrix *= transform3D::Scale(2, 1, 2);
    RenderMesh(meshes["plane"], shaders["Tema2Shader"], modelMatrix, camera, glm::vec3(102.0f / 255, 178.0f / 255, 1));

    modelMatrix = glm::mat4(1);
    for (const auto& pos : treesPositions) {
        modelMatrix = glm::mat4(1);
        modelMatrix *= transform3D::Translate(pos.x, 0, pos.y);
        modelMatrix *= transform3D::Scale(0.6f, 0.6f, 0.6f);
        RenderMesh(meshes["tree"], shaders["Tema2Shader"], modelMatrix, camera);
    }
}

bool Tema2::SameSide(glm::vec3 P1, glm::vec3 P2, glm::vec3 A, glm::vec3 B)
{
    glm::vec3 position1 = glm::cross(B - A, P1 - A);
    glm::vec3 position2 = glm::cross(B - A, P2 - A);
    if (glm::dot(position1, position2) >= 0) {
        return true;
    }
    return false;
}

bool Tema2::IsPointInTriangle(glm::vec3 P, glm::vec3 A, glm::vec3 B, glm::vec3 C)
{
    if (SameSide(P, A, B, C) && SameSide(P, B, A, C) && SameSide(P, C, A, B)) {
        return true;
    }
    return false;
}

bool Tema2::IsOnTrack(glm::vec3 targetPoint)
{
    glm::vec3 A, B, C, D;
    for (int i = 0; i < outerVertices.size(); i++) {
        A = outerVertices[i % outerVertices.size()];
        A.x *= 2.75f; A.z *= 3;
        B = innerVertices[i % innerVertices.size()];
        B.x *= 2.75f; B.z *= 3;
        C = outerVertices[(i + 1) % outerVertices.size()];
        C.x *= 2.75f; C.z *= 3;
        D = innerVertices[(i + 1) % innerVertices.size()];
        D.x *= 2.75f; D.z *= 3;
        if (IsPointInTriangle(targetPoint, A, B, C) || IsPointInTriangle(targetPoint, C, D, B)) {
            return true;
        }
    }
    return false;
}

void Tema2::RenderCars(float deltaTimeSeconds, implemented::Camera *camera)
{
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(camera->GetTargetPosition().x, 0.1f, camera->GetTargetPosition().z);
    modelMatrix *= transform3D::RotateOY(carAngularStep);
    modelMatrix *= transform3D::Scale(0.3f, 0.3f, 0.3f);
    RenderMesh(meshes["car"], shaders["Tema2Shader"], modelMatrix, camera);

    MoveCar(translateXCar_1, translateZCar_1, indexCar_1, paths[0], deltaTimeSeconds);
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(translateXCar_1 * 2.75f, 0.1f, translateZCar_1 * 2.75f);
    modelMatrix *= transform3D::RotateOY(M_PI / 2 + angles[indexCar_1]);
    modelMatrix *= transform3D::Scale(0.3f, 0.3f, 0.3f);
    RenderMesh(meshes["car"], shaders["Tema2Shader"], modelMatrix, camera, glm::vec3(1, 0, 0));

    MoveCar(translateXCar_2, translateZCar_2, indexCar_2, paths[1], deltaTimeSeconds);
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(translateXCar_2 * 2.75f, 0.1f, translateZCar_2 * 2.75f);
    modelMatrix *= transform3D::RotateOY(M_PI / 2 + angles[indexCar_2]);
    modelMatrix *= transform3D::Scale(0.3f, 0.3f, 0.3f);
    RenderMesh(meshes["car"], shaders["Tema2Shader"], modelMatrix, camera, glm::vec3(0, 1, 0));

    MoveCar(translateXCar_3, translateZCar_3, indexCar_3, paths[2], deltaTimeSeconds);
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(translateXCar_3 * 2.75f, 0.1f, translateZCar_3 * 2.75f);
    modelMatrix *= transform3D::RotateOY(M_PI / 2 + angles[indexCar_3]);
    modelMatrix *= transform3D::Scale(0.3f, 0.3f, 0.3f);
    RenderMesh(meshes["car"], shaders["Tema2Shader"], modelMatrix, camera, glm::vec3(0, 0, 1));
}

bool Tema2::CollisionDetected(glm::vec3 enemy, implemented::Camera* camera)
{
    enemy *= 2.75f;
    glm::vec3 player = camera->GetTargetPosition();
    float distance = sqrt((player.x - enemy.x) * (player.x - enemy.x) +
                          (player.z - enemy.z) * (player.z - enemy.z));
    return distance < (carRadius / 2.75f);
}


void Tema2::Update(float deltaTimeSeconds)
{
    RenderEnvironment(camera);
    RenderCars(deltaTimeSeconds, camera);

    glClear(GL_DEPTH_BUFFER_BIT);
    glViewport(minimapArea.x, minimapArea.y, minimapArea.width, minimapArea.height);
    projectionMatrix = orthoMatrix;

    RenderEnvironment(minimapCamera);
    RenderCars(deltaTimeSeconds, minimapCamera);
    minimapCamera->position.x = camera->GetTargetPosition().x;
    minimapCamera->position.z = camera->GetTargetPosition().z;

    projectionMatrix = perspectiveMatrix;
}


void Tema2::FrameEnd()
{

}


void Tema2::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix, implemented::Camera* camera, const glm::vec3& color)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    int location = glGetUniformLocation(shader->program, "object_color");
    glUniform3fv(location, 1, glm::value_ptr(color));

    location = glGetUniformLocation(shader->program, "Pcar");
    glUniform3fv(location, 1, glm::value_ptr(camera->GetTargetPosition()));

    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}

/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    float cameraSpeed = 3.0f;

    if (CollisionDetected(glm::vec3(translateXCar_1, 0, translateZCar_1), camera) ||
        CollisionDetected(glm::vec3(translateXCar_2, 0, translateZCar_2), camera) ||
        CollisionDetected(glm::vec3(translateXCar_3, 0, translateZCar_3), camera)) {
        return;
    }

    if (window->KeyHold(GLFW_KEY_W)) {
        glm::vec3 targetPosition = camera->GetTargetPosition();
        glm::vec3 dir = glm::normalize(glm::vec3(camera->forward.x, 0, camera->forward.z));
        targetPosition += dir * cameraSpeed * deltaTime;
        if (IsOnTrack(targetPosition)) {
            camera->MoveForward(cameraSpeed * deltaTime);
            minimapCamera->MoveForward(cameraSpeed * deltaTime);
        }
    }
    if (window->KeyHold(GLFW_KEY_A)) {
        camera->RotateThirdPerson_OY(1.4f * deltaTime);
        carAngularStep += 1.4f * deltaTime;
    }
    if (window->KeyHold(GLFW_KEY_S)) {
        glm::vec3 targetPosition = camera->GetTargetPosition();
        glm::vec3 dir = glm::normalize(glm::vec3(camera->forward.x, 0, camera->forward.z));
        targetPosition += dir * (-cameraSpeed * deltaTime);
        if (IsOnTrack(targetPosition)) {
            camera->MoveForward(-cameraSpeed * deltaTime);
            minimapCamera->MoveForward(-cameraSpeed * deltaTime);
        }
    }
    if (window->KeyHold(GLFW_KEY_D)) {
        camera->RotateThirdPerson_OY(-1.4f * deltaTime);
        carAngularStep -= 1.4f * deltaTime;
    }
}


void Tema2::OnKeyPress(int key, int mods)
{
}


void Tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{

}
