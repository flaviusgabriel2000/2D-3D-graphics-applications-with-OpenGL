#include "lab_m1/Tema3/Tema3.h"
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


Tema3::Tema3()
{
}


Tema3::~Tema3()
{
}

void Tema3::CreateHill()
{
    vector<glm::vec3> vertices
    {
        glm::vec3(0.5f,   0.5f, 0.0f),
        glm::vec3(0.5f,  -0.5f, 0.0f),
        glm::vec3(-0.5f, -0.5f, 0.0f),
        glm::vec3(-0.5f,  0.5f, 0.0f),

    };

    vector<glm::vec3> normals
    {
        glm::vec3(0, 1, 1),
        glm::vec3(1, 0, 1),
        glm::vec3(1, 0, 0),
        glm::vec3(0, 1, 0)
    };

    vector<glm::vec2> textureCoords
    {
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),
        glm::vec2(0.0f, 0.0f),
    };

    vector<unsigned int> indices =
    {
        0, 1, 3,
        1, 2, 3
    };

    Mesh* mesh = new Mesh("hill");
    mesh->InitFromData(vertices, normals, textureCoords, indices);
    meshes[mesh->GetMeshID()] = mesh;

    Texture2D* texture = new Texture2D();
    texture->Load2D(PATH_JOIN(sourceTextureDir, "snow.jpg").c_str(), GL_REPEAT);
    mapTextures["snow"] = texture;

}

void Tema3::CreatePlayer()
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(-0.2f, 0,  -0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(-0.2f, 0,  0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(-0.1f, 0,  -0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 2550)),
        VertexFormat(glm::vec3(-0.1f, 0,  0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(-0.2f, 0.02f,  -0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(-0.2f, 0.02f,  0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(-0.1f, 0.02f,  -0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(-0.1f, 0.02f,  0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),

        VertexFormat(glm::vec3(0.1f, 0,  -0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.1f, 0,  0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.2f, 0,  -0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.2f, 0,  0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.1f, 0.02f,  -0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.1f, 0.02f,  0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.2f, 0.02f,  -0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.2f, 0.02f,  0.5f), glm::vec3(0.0f / 255, 204.0f / 255, 102.0f / 255)),

        VertexFormat(glm::vec3(-0.2f, 0,  -0.2f), glm::vec3(0.0f / 255, 51.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(-0.2f, 0,  0.2f), glm::vec3(0.0f / 255, 51.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.2f, 0,  -0.2f), glm::vec3(0.0f / 255, 51.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.2f, 0,  0.2f), glm::vec3(0.0f / 255, 51.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(-0.2f, 0.6f,  -0.2f), glm::vec3(0.0f / 255, 51.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(-0.2f, 0.6f,  0.2f), glm::vec3(0.0f / 255, 51.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.2f, 0.6f,  -0.2f), glm::vec3(0.0f / 255, 51.0f / 255, 102.0f / 255)),
        VertexFormat(glm::vec3(0.2f, 0.6f,  0.2f), glm::vec3(0.0f / 255, 51.0f / 255, 102.0f / 255)),
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
        8, 10, 12,

        16, 17, 18,
        17, 19, 18,
        18, 19, 23,
        18, 23, 22,
        17, 23, 19,
        17, 20, 23,
        22, 23, 20,
        16, 20, 17,
        17, 20, 21,
        18, 22, 20,
        16, 18, 20,
    };

    Mesh* player = new Mesh("player");
    player->InitFromData(vertices, indices);
    AddMeshToList(player);
}

void Tema3::CreateTree()
{
    Mesh* mesh = new Mesh("trunk");
    mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
    meshes[mesh->GetMeshID()] = mesh;

    Texture2D* texture = new Texture2D();
    texture->Load2D(PATH_JOIN(sourceTextureDir, "trunk.jpg").c_str(), GL_REPEAT);
    mapTextures["trunk"] = texture;


    mesh = new Mesh("crown");
    mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "cone.obj");
    meshes[mesh->GetMeshID()] = mesh;

    texture = new Texture2D();
    texture->Load2D(PATH_JOIN(sourceTextureDir, "crown.jpg").c_str(), GL_REPEAT);
    mapTextures["crown"] = texture;
}

void Tema3::CreateStone()
{
    Mesh* mesh = new Mesh("stone");
    mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
    meshes[mesh->GetMeshID()] = mesh;

    Texture2D* texture = new Texture2D();
    texture->Load2D(PATH_JOIN(sourceTextureDir, "stone.jpg").c_str(), GL_REPEAT);
    mapTextures["stone"] = texture;
}

void Tema3::CreateLightingPole()
{
    Mesh* mesh = new Mesh("lighting_pole");
    mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
    meshes[mesh->GetMeshID()] = mesh;

    Texture2D* texture = new Texture2D();
    texture->Load2D(PATH_JOIN(sourceTextureDir, "lighting_pole.jpg").c_str(), GL_REPEAT);
    mapTextures["lighting_pole"] = texture;

    texture = new Texture2D();
    texture->Load2D(PATH_JOIN(sourceTextureDir, "lighting_pole2.jpg").c_str(), GL_REPEAT);
    mapTextures["lighting_pole2"] = texture;
}

void Tema3::CreateGift()
{
    Mesh* mesh = new Mesh("gift");
    mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
    meshes[mesh->GetMeshID()] = mesh;

    Texture2D* texture = new Texture2D();
    texture->Load2D(PATH_JOIN(sourceTextureDir, "gift.jpg").c_str(), GL_REPEAT);
    mapTextures["gift"] = texture;
}


void Tema3::Init()
{
    srand((unsigned)time(NULL));

    fov = RADIANS(60);
    aspect = window->props.aspectRatio;
    zNearP = 0.01f;
    zFarP = 200.0f;


    camera = new implemented::Camera();
    camera->Set(glm::vec3(0, 1.5f, 5), glm::vec3(0, -1, 0), glm::vec3(0, 1, 0));

    projectionMatrix = glm::perspective(fov, aspect, zNearP, zFarP);

    Shader* shader = new Shader("Tema3Shader");
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
    shader->CreateAndLink();
    shaders[shader->GetName()] = shader;

    shader = new Shader("HillShader");
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "shaders", "HillVertexShader.glsl"), GL_VERTEX_SHADER);
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "shaders", "HillFragmentShader.glsl"), GL_FRAGMENT_SHADER);
    shader->CreateAndLink();
    shaders[shader->GetName()] = shader;

    shader = new Shader("PlayerShader");
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "shaders", "PlayerVertexShader.glsl"), GL_VERTEX_SHADER);
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "shaders", "PlayerFragmentShader.glsl"), GL_FRAGMENT_SHADER);
    shader->CreateAndLink();
    shaders[shader->GetName()] = shader;

    CreateHill();
    CreatePlayer();
    CreateTree();
    CreateStone();
    CreateLightingPole();
    CreateGift();

    for (int i = 0; i < MAX_SPOTLIGHTS; i++) {
        spotLightPosition[i] = glm::vec3(0);
        if (i < MAX_POINTLIGHTS) {
            pointLightPosition[i] = glm::vec3(0);
        }  
    }
}

Mesh* Tema3::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices)
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


void Tema3::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema3::RenderLightingPole(float distanceX, float distanceYZ, int index)
{
    spotLightPosition[index] = glm::vec3(distanceX - 0.6f, 0.7f - sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ + 0.2f);
    spotLightPosition[index + 1] = glm::vec3(distanceX + 0.7f, 0.7f - sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ + 0.2f);

    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(distanceX, 0.4f - sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ);
    modelMatrix *= transform3D::Scale(0.07f, 0.8f, 0.07f);
    RenderMesh(meshes["lighting_pole"], shaders["Tema3Shader"], modelMatrix, mapTextures["lighting_pole2"], glm::vec3(1));

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(distanceX, 0.8f - sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ);
    modelMatrix *= transform3D::Scale(0.5f, 0.08f, 0.08f);
    RenderMesh(meshes["lighting_pole"], shaders["HillShader"], modelMatrix, mapTextures["lighting_pole"], glm::vec3(1));
}

void Tema3::RenderTree(float distanceX, float distanceYZ, int index)
{
    pointLightPosition[index] = glm::vec3(distanceX, 0.65f - sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ);

    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(distanceX, 0.3f - sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ);
    modelMatrix *= transform3D::Scale(0.1f, 0.5f, 0.1f);
    RenderMesh(meshes["trunk"], shaders["Tema3Shader"], modelMatrix, mapTextures["trunk"]);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(distanceX, 0.6f - sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ);
    modelMatrix *= transform3D::Scale(0.25f, 0.2f, 0.25f);
    RenderMesh(meshes["crown"], shaders["Tema3Shader"], modelMatrix, mapTextures["crown"]);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(distanceX, 0.8f - sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ);
    modelMatrix *= transform3D::Scale(0.2f, 0.2f, 0.2f);
    RenderMesh(meshes["crown"], shaders["Tema3Shader"], modelMatrix, mapTextures["crown"]);
}

void Tema3::RenderStone(float distanceX, float distanceYZ)
{
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(-0.1f + distanceX, -sin(M_PI / 6) * distanceYZ, -0.05f + cos(M_PI / 6) * distanceYZ);
    modelMatrix *= transform3D::Scale(0.26f, 0.26f, 0.26f);
    RenderMesh(meshes["stone"], shaders["Tema3Shader"], modelMatrix, mapTextures["stone"]);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(distanceX, -sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ);
    modelMatrix *= transform3D::Scale(0.2f, 0.2f, 0.2f);
    RenderMesh(meshes["stone"], shaders["Tema3Shader"], modelMatrix, mapTextures["stone"]);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(0.12f + distanceX, -sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ);
    modelMatrix *= transform3D::Scale(0.23f, 0.23f, 0.23f);
    RenderMesh(meshes["stone"], shaders["Tema3Shader"], modelMatrix, mapTextures["stone"]);
}

void Tema3::RenderGift(float distanceX, float distanceYZ, int index)
{
    pointLightPosition[index] = glm::vec3(distanceX + 0.1f, 0.7f - sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ);

    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(distanceX, 0.15f - sin(M_PI / 6) * distanceYZ, cos(M_PI / 6) * distanceYZ);
    modelMatrix *= transform3D::Scale(0.25f, 0.25f, 0.25f);
    RenderMesh(meshes["gift"], shaders["Tema3Shader"], modelMatrix, mapTextures["gift"]);
}

void Tema3::RenderPlayerAndHill()
{
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(translateX, -translateYZ * sin(M_PI / 6), translateYZ * cos(M_PI / 6));
    modelMatrix *= transform3D::RotateOX(-M_PI / 3);
    modelMatrix *= transform3D::Scale(15, 10, 10);
    RenderMesh(meshes["hill"], shaders["HillShader"], modelMatrix, mapTextures["snow"]);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(translateX, 0.05f - translateYZ * sin(M_PI / 6), translateYZ * cos(M_PI / 6));
    modelMatrix *= transform3D::RotateOX(M_PI / 6);
    modelMatrix *= transform3D::RotateOY(-playerAngularStep);
    modelMatrix *= transform3D::Scale(0.6f, 0.6f, 0.6f);
    RenderMesh(meshes["player"], shaders["PlayerShader"], modelMatrix);
}

void Tema3::GenerateRandomObjects()
{
    if (timer >= 0.2f) {
        /* 0 = tree, 1 = lighting pole, 2 = stone, 3 = gift */
        int nextObject = rand() % 4;
        float posX = (3 - (-3)) * ((float)rand() / RAND_MAX) + (-3);
        float posZ = (5 - (4)) * ((float)rand() / RAND_MAX) + (4);

        switch (nextObject) {
        case 0: {
            randomObjects.push_back(RandomObject(translateX + posX, translateYZ + posZ, Tree, false, pointLightsIndex % MAX_POINTLIGHTS));
            float R = (float)rand() / RAND_MAX;
            float G = (float)rand() / RAND_MAX;
            float B = (float)rand() / RAND_MAX;
            glm::vec3 pointLightColor = glm::vec3(R, G, B);
            pointLightColors[pointLightsIndex % MAX_POINTLIGHTS] = pointLightColor;
            pointLightsIndex++;
            break;
        }
        case 1: {
            randomObjects.push_back(RandomObject(translateX + posX, translateYZ + posZ, LightingPole, false, spotLightsIndex % MAX_SPOTLIGHTS));
            spotLightsIndex += 2;
            break;
        }
        case 2: {
            randomObjects.push_back(RandomObject(translateX + posX, translateYZ + posZ, Stone, false, -1));
            break;
        }
        case 3: {
            randomObjects.push_back(RandomObject(translateX + posX, translateYZ + posZ, Gift, false, pointLightsIndex % MAX_POINTLIGHTS));
            float R = (float)rand() / RAND_MAX;
            float G = (float)rand() / RAND_MAX;
            float B = (float)rand() / RAND_MAX;
            glm::vec3 pointLightColor = glm::vec3(R, G, B);
            pointLightColors[pointLightsIndex % MAX_POINTLIGHTS] = pointLightColor;
            pointLightsIndex++;
            break;
        }
        default:
            break;
        }
        timer = 0;
    }

    for (auto &it = randomObjects.begin(); it != randomObjects.end(); ) {
        if (abs(translateYZ * cos(M_PI / 6) - it->posZ * cos(M_PI / 6)) < MAX_DELETION_DISTANCE) {
            switch (it->type) {
            case Tree: {
                RenderTree(it->posX, it->posZ, it->index);
                break;
            }
            case LightingPole: {
                RenderLightingPole(it->posX, it->posZ, it->index);
                break;
            }
            case Stone: {
                RenderStone(it->posX, it->posZ);
                break;
            }
            case Gift: {
                RenderGift(it->posX, it->posZ, it->index);
                break;
            }
            default:
                break;
            }
            it++;
        }
        else {
            if (it->type == LightingPole) {
                spotLightPosition[it->index] = glm::vec3(0);
                spotLightPosition[it->index + 1] = glm::vec3(0);
            }
            if (it->type == Tree || it->type == Gift) {
                pointLightPosition[it->index] = glm::vec3(0);
            }
            it = randomObjects.erase(it);
        }
    }
}

void Tema3::CheckCollision()
{
    for (auto &object = randomObjects.begin(); object != randomObjects.end(); ) {
        if (!object->collided && abs(translateX - object->posX) < MAX_COLLISION_TOLERANCE && abs(translateYZ - object->posZ) < MAX_COLLISION_TOLERANCE) {
            object->collided = true;
            if (object->type == Gift) {
                playerScore++;
                pointLightPosition[object->index] = glm::vec3(0);
                object = randomObjects.erase(object);
            }
            else {
                gameOver = true;
                cout << "Game Over. Total score: " << playerScore << endl << "Press R to restart the game." << endl;
                break;
            }
        }
        object++;
    }
}


void Tema3::Update(float deltaTimeSeconds)
{
    CheckCollision();
    if (!gameOver) {
        translateX += 3 * deltaTimeSeconds * (-sin(playerAngularStep));
        translateYZ += 2.7f * deltaTimeSeconds;
        camera->position.x = translateX;
        camera->position.y -= 2.7f * deltaTimeSeconds * sin(M_PI / 6);
        camera->position.z += 2.7f * deltaTimeSeconds * cos(M_PI / 6);
        timer += deltaTimeSeconds;
        texcoordShift.y += 0.27f * deltaTimeSeconds;
        texcoordShift.x += 0.2f * deltaTimeSeconds * (-sin(playerAngularStep));
    }

    GenerateRandomObjects();
    RenderPlayerAndHill();
}


void Tema3::FrameEnd()
{
}


void Tema3::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix, Texture2D* texture, const glm::vec3& color)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    glUseProgram(shader->program);

    int spotLocation = glGetUniformLocation(shader->program, "spot_light_pos");
    glUniform3fv(spotLocation, 20, glm::value_ptr(spotLightPosition[0]));

    int pointLocation = glGetUniformLocation(shader->program, "point_light_pos");
    glUniform3fv(pointLocation, 15, glm::value_ptr(pointLightPosition[0]));

    int pointLightColorsLocation = glGetUniformLocation(shader->program, "pointLightColors");
    glUniform3fv(pointLightColorsLocation, 15, glm::value_ptr(pointLightColors[0]));

    int light_direction = glGetUniformLocation(shader->program, "light_direction");
    glUniform3f(light_direction, directionalLightDir.x, directionalLightDir.y, directionalLightDir.z);

    // Set eye position (camera position) uniform
    glm::vec3 eyePosition = camera->position;
    int eye_position = glGetUniformLocation(shader->program, "eye_position");
    glUniform3f(eye_position, eyePosition.x, eyePosition.y, eyePosition.z);

    // Set material property uniforms (shininess, kd, ks, object color) 
    int material_shininess = glGetUniformLocation(shader->program, "material_shininess");
    glUniform1i(material_shininess, materialShininess);

    int material_kd = glGetUniformLocation(shader->program, "material_kd");
    glUniform1f(material_kd, materialKd);

    int material_ks = glGetUniformLocation(shader->program, "material_ks");
    glUniform1f(material_ks, materialKs);


    int location = glGetUniformLocation(shader->program, "object_color");
    glUniform3fv(location, 1, glm::value_ptr(color));

    location = glGetUniformLocation(shader->program, "texcoordShift");
    glUniform2fv(location, 1, glm::value_ptr(texcoordShift));

    if (texture)
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture->GetTextureID());
        glUniform1i(glGetUniformLocation(shader->GetProgramID(), "textureSampler"), 0);
    }

    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema3::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema3::OnKeyPress(int key, int mods)
{
    if (gameOver && key == GLFW_KEY_R) {
        translateX = 0;
        translateYZ = 0;
        camera->position.x = 0;
        camera->position.y = 1.5f;
        camera->position.z = 5;
        timer = 0;
        texcoordShift.y = 0;
        texcoordShift.x = 0;

        randomObjects.clear();
        playerScore = 0;
        gameOver = false;

        for (int i = 0; i < 20; i++) {
            spotLightPosition[i] = glm::vec3(0);
            if (i < 15) {
                pointLightPosition[i] = glm::vec3(0);
            }
        }
    }
}


void Tema3::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    playerAngularStep = atan((resolution.x / static_cast<float>(2) - mouseX) / (resolution.y / static_cast<float>(2) + 130));
    if (abs(DEGREES(playerAngularStep)) > MAX_PLAYER_ROTATION_ANGLE) {
        if (playerAngularStep > 0) {
            playerAngularStep = M_PI_4;
        }
        else if (playerAngularStep < 0) {
            playerAngularStep = -M_PI_4;
        }
    }
}


void Tema3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Tema3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema3::OnWindowResize(int width, int height)
{

}
