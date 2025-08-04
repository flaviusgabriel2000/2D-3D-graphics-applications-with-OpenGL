#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/Object2Dim.h"

using namespace std;
using namespace m1;

constexpr auto TIMEOUT = 7;

/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}

void Tema1::BuildDuck(int triangleSide)
{
    Mesh* body = Object2Dim::CreateTriangle("body",
        glm::vec3(0, 0, 0),
        glm::vec3(0, triangleSide, 0),
        glm::vec3(1.5f * triangleSide, 0.5f * triangleSide, 0),
        glm::vec3(0.5f, 0.35f, 0.05f));
    AddMeshToList(body);

    Mesh* beak = Object2Dim::CreateTriangle("beak",
        glm::vec3(1.7f * triangleSide, 0.35f * triangleSide, 0),
        glm::vec3(1.7f * triangleSide, 0.55f * triangleSide, 0),
        glm::vec3(2 * triangleSide, 0.4f * triangleSide, 0),
        glm::vec3(1.0f, 0.5f, 0.0f));
    AddMeshToList(beak);

    Mesh* uwing = Object2Dim::CreateTriangle("uwing",
        glm::vec3(0.2f * triangleSide, 0.6f * triangleSide, 0),
        glm::vec3(triangleSide, 0.6f * triangleSide, 0),
        glm::vec3(0.4f * triangleSide, 1.45f * triangleSide, 0),
        glm::vec3(0.5f, 0.35f, 0.05f));
    AddMeshToList(uwing);

    Mesh* lwing = Object2Dim::CreateTriangle("lwing",
        glm::vec3(0.2f * triangleSide, 0.4f * triangleSide, 0),
        glm::vec3(triangleSide, 0.4f * triangleSide, 0),
        glm::vec3(0.4f * triangleSide, -0.45f * triangleSide, 0),
        glm::vec3(0.5f, 0.35f, 0.05f));
    AddMeshToList(lwing);

    Mesh* head = Object2Dim::CreateCircle("head", 6, 2, glm::vec3(0, 0.27f, 0), 100);
    AddMeshToList(head);
}

void Tema1::CreatePlayerData()
{
    Mesh *playerLife = Object2Dim::CreateCircle("life", 0, 0, glm::vec3(0.6f, 0, 0), 100);
    AddMeshToList(playerLife);

    Mesh* playerAmmo = Object2Dim::CreateRectangle("ammo",
        glm::vec3(0, 0, 0),
        glm::vec3(5, 0, 0),
        glm::vec3(0, 10, 0),
        glm::vec3(5, 10, 0),
        glm::vec3(0, 0.15f, 0),
        true);
    AddMeshToList(playerAmmo);

    Mesh* scoreWireframe = Object2Dim::CreateRectangle("scoreWireframe",
        glm::vec3(0, 0, 0),
        glm::vec3(261, 0, 0),
        glm::vec3(261, 50, 0),
        glm::vec3(0, 50, 0),
        glm::vec3(1, 1, 1));
    AddMeshToList(scoreWireframe);

    Mesh* playerScore = Object2Dim::CreateRectangle("playerScore",
        glm::vec3(0, 0, 0),
        glm::vec3(60, 0, 0),
        glm::vec3(0, 50, 0),
        glm::vec3(60, 50, 0),    
        glm::vec3(0, 0, 1),
        true);
    AddMeshToList(playerScore);
}

void Tema1::CreateEnvironmentData()
{
    Mesh* meadow = Object2Dim::CreateRectangle("meadow",
        glm::vec3(0, 0, 0),
        glm::vec3(60, 0, 0),
        glm::vec3(0, 50, 0),
        glm::vec3(60, 50, 0),
        glm::vec3(0, 0.3f, 0),
        true);
    AddMeshToList(meadow);

    Mesh* grass = Object2Dim::CreateTriangle("grass",
        glm::vec3(0, 0, 0),
        glm::vec3(10, 0, 0),
        glm::vec3(4.5f, 10, 0),
        glm::vec3(0, 0.3f, 0));
    AddMeshToList(grass);

    for (int i = 0; i <= 150; i++) {
        grassAngles.push_back((M_PI / 3 - M_PI / 6) * ((float)rand() / RAND_MAX) + M_PI / 6);
    }
    grassAngularStep = 0;
    grassAngularStepSign = 1;


    Mesh* moon = Object2Dim::CreateCircle("moon", 0, 0, glm::vec3(0.8f, 0.6f, 0.2f), 100);
    AddMeshToList(moon);
    Mesh* star = Object2Dim::CreateCircle("star", 0, 0, glm::vec3(1, 1, 1), 100);
    AddMeshToList(star);
    Mesh* blackCircle = Object2Dim::CreateCircle("blackCircle", 0, 0, glm::vec3(0, 0, 0), 100);
    AddMeshToList(blackCircle);

    stars.push_back(std::make_pair(120, 560));
    stars.push_back(std::make_pair(130, 650));
    stars.push_back(std::make_pair(110, 667));
    stars.push_back(std::make_pair(205, 540));
    stars.push_back(std::make_pair(345, 632));
    stars.push_back(std::make_pair(672, 571));
    stars.push_back(std::make_pair(868, 552));
    stars.push_back(std::make_pair(733, 423));
    stars.push_back(std::make_pair(486, 572));
    stars.push_back(std::make_pair(456, 492));
    stars.push_back(std::make_pair(355, 528));
    stars.push_back(std::make_pair(275, 478));
    stars.push_back(std::make_pair(375, 678));
    stars.push_back(std::make_pair(455, 683));
    stars.push_back(std::make_pair(659, 669));
    stars.push_back(std::make_pair(759, 619));
    stars.push_back(std::make_pair(832, 659));
    stars.push_back(std::make_pair(570, 480));
    stars.push_back(std::make_pair(780, 500));
    stars.push_back(std::make_pair(111, 500));
    stars.push_back(std::make_pair(1100, 600));
    stars.push_back(std::make_pair(1177, 557));
    stars.push_back(std::make_pair(1009, 532));
    stars.push_back(std::make_pair(898, 478));
    stars.push_back(std::make_pair(1108, 498));
}

void Tema1::GetDuckDirection(float angle)
{
    if (abs(angle - (M_PI / 2)) < 4.37115e-08 && !duckHit) { // Vertical up
        translateXSign = 0;
        translateYSign = 1;
    }
    else if (abs(angle - 3 * M_PI / 2) < 1.2e-08 && duckHit) { // Vertical down
        translateXSign = 0;
        translateYSign = -1;
    }
    else if (angle > 0 && angle < M_PI / 2) { // Quadrant I
        translateXSign = 1;
        translateYSign = 1;
    }
    else if (angle > M_PI / 2 && angle < M_PI) { // Quadrant II
        translateXSign = -1;
        translateYSign = 1;
    }
    else if (angle > M_PI && angle < 3 * M_PI / 2) { // Quadrant III
        translateXSign = -1;
        translateYSign = -1;
    }
    else if (angle > 3 * M_PI / 2 && angle < 2 * M_PI) { // Quadrant IV
        translateXSign = 1;
        translateYSign = -1;
    }
}

bool Tema1::CollisionDetected()
{
    if (angle >= 0 && angle <= M_PI_2) { // Quadrant I
        if (translateY + 1.7f * triangleSide >= resolution.y) {
            angle = 2 * M_PI - angle;
            return true;
        }
        if (translateX + 1.3f * triangleSide >= resolution.x) {
            angle = M_PI - angle;
            return true;
        }
    }
    else if (angle >= M_PI_2 && angle <= M_PI) { // Quadrant II
        if (translateY + 1.7f * triangleSide >= resolution.y) {
            angle = 2 * M_PI - angle;
            return true;
        }
        if (translateX - 0.3f * triangleSide <= 0) {
            angle = M_PI - angle;
            return true;
        }
    }
    else if (angle >= M_PI && angle <= 3 * M_PI / 2) { // Quadrant III
        if (translateY - 0.7f * triangleSide <= 0) {
            angle = 2 * M_PI - angle;
            return true;
        }
        if (translateX - 0.3f * triangleSide <= 0) {
            angle = angle + M_PI / 2;
            return true;
        }
    }
    else if (angle >= 3 * M_PI / 2 && angle <= 2 * M_PI) { // Quadrant IV
        if (translateY - 0.7f * triangleSide <= 0) {
            angle = 2 * M_PI - angle;
            return true;
        }
        if (translateX + 1.3f * triangleSide >= resolution.x) {
            angle = angle - M_PI / 2;
            return true;
        }
    }
    return false;
}

void Tema1::GenerateInitialPosition()
{
    for (int i = 0; i < 5; i++) {
        // A random initial angle between [PI/6, 5PI/6]
        angle = (5 * M_PI / 6 - M_PI / 6) * ((float)rand() / RAND_MAX) + M_PI / 6;
    }
    GetDuckDirection(angle);

    // A random initial x position between [200, resolution.x - 200]
    translateX = (resolution.x - 400) * ((float)rand() / RAND_MAX) + 200;
    translateY = -200;
}


void Tema1::Init()
{
    srand(static_cast <unsigned> (time(NULL)));

    resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    triangleSide = 100;
    wingAngularStep = 0;
    timeOnScreen = 0;
    duckCount = 0;
    speedFactor = 5;
    playerLives = 3;
    playerAmmo = 3;
    playerScore = 0;
    cursorInDuckArea = false;
    duckHit = false;

    cxbody = (1.5f * triangleSide) / 3;
    cybody = (triangleSide + 0.5f * triangleSide) / 3;
    cxuwing = (0.2f * triangleSide + triangleSide + 0.4f * triangleSide) / 3;
    cyuwing = (0.6f * triangleSide + 0.6f * triangleSide + 1.45f * triangleSide) / 3;
    cxlwing = (0.2f * triangleSide + triangleSide + 0.4f * triangleSide) / 3;
    cylwing = (0.4f * triangleSide + 0.4 * triangleSide - 0.45f * triangleSide) / 3;

    BuildDuck(triangleSide);
    GenerateInitialPosition();

    CreatePlayerData();
    CreateEnvironmentData();

    // Hitbox vertices
    v1 = glm::vec3(0, 0, 0);
    v2 = glm::vec3(0.9f * triangleSide, 0, 0);
    v3 = glm::vec3(0.9f * triangleSide, 2 * triangleSide, 0);
    v4 = glm::vec3(0, 2 * triangleSide, 0);
}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::RenderDuck(float deltaTimeSeconds)
{
    glm::mat3 duckMatrix = glm::mat3(1);
    duckMatrix *= transform2D::Translate(translateX, translateY);
    duckMatrix *= transform2D::Translate(cxbody, cybody);
    duckMatrix *= transform2D::Rotate(angle);
    duckMatrix *= transform2D::Translate(-cxbody, -cybody);

    modelMatrix = glm::mat3(1);
    modelMatrix *= duckMatrix;
    modelMatrix *= transform2D::Scale(25, 25);
    RenderMesh2D(meshes["head"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= duckMatrix;
    RenderMesh2D(meshes["body"], shaders["VertexColor"], modelMatrix);


    Tema1::wingAngularStep += 2 * deltaTimeSeconds;
    if (wingAngularStep > M_PI / 10) {
        wingAngularStep = 0;
    }
    modelMatrix = glm::mat3(1);
    modelMatrix *= duckMatrix;
    modelMatrix *= transform2D::Translate(cxuwing, cyuwing);
    modelMatrix *= transform2D::Rotate(wingAngularStep);
    modelMatrix *= transform2D::Translate(-cxuwing, -cyuwing);
    RenderMesh2D(meshes["uwing"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= duckMatrix;
    modelMatrix *= transform2D::Translate(cxlwing, cylwing);
    modelMatrix *= transform2D::Rotate(-wingAngularStep);
    modelMatrix *= transform2D::Translate(-cxlwing, -cylwing);
    RenderMesh2D(meshes["lwing"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= duckMatrix;
    RenderMesh2D(meshes["beak"], shaders["VertexColor"], modelMatrix);
}

void Tema1::RenderPlayerLives()
{
    glm::mat3 lifeMatrix = glm::mat3(1);
    if (playerLives >= 1) {
        lifeMatrix *= transform2D::Translate(40, 680);
        lifeMatrix *= transform2D::Scale(25, 25);
        RenderMesh2D(meshes["life"], shaders["VertexColor"], lifeMatrix);
    }
    if (playerLives >= 2) {
        lifeMatrix = glm::mat3(1);
        lifeMatrix *= transform2D::Translate(100, 680);
        lifeMatrix *= transform2D::Scale(25, 25);
        RenderMesh2D(meshes["life"], shaders["VertexColor"], lifeMatrix);
    }
    if (playerLives >= 3) {
        lifeMatrix = glm::mat3(1);
        lifeMatrix *= transform2D::Translate(160, 680);
        lifeMatrix *= transform2D::Scale(25, 25);
        RenderMesh2D(meshes["life"], shaders["VertexColor"], lifeMatrix);
    }
}

void Tema1::RenderPlayerAmmo()
{
    glm::mat3 ammoMatrix;
    if (playerAmmo >= 1) {
        ammoMatrix = glm::mat3(1);
        ammoMatrix *= transform2D::Translate(32.5f, 590);
        ammoMatrix *= transform2D::Scale(3, 5);
        RenderMesh2D(meshes["ammo"], shaders["VertexColor"], ammoMatrix);
    }
    if (playerAmmo >= 2) {
        ammoMatrix = glm::mat3(1);
        ammoMatrix *= transform2D::Translate(92.5f, 590);
        ammoMatrix *= transform2D::Scale(3, 5);
        RenderMesh2D(meshes["ammo"], shaders["VertexColor"], ammoMatrix);
    }
    if (playerAmmo >= 3) {
        ammoMatrix = glm::mat3(1);
        ammoMatrix *= transform2D::Translate(152.5f, 590);
        ammoMatrix *= transform2D::Scale(3, 5);
        RenderMesh2D(meshes["ammo"], shaders["VertexColor"], ammoMatrix);
    }
}

void Tema1::RenderPlayerScore()
{
    glm::mat3 scoreMatrix = glm::mat3(1);
    scoreMatrix *= transform2D::Translate(990, 650);
    RenderMesh2D(meshes["scoreWireframe"], shaders["VertexColor"], scoreMatrix);

    if (playerScore >= 10) {
        scoreMatrix = glm::mat3(1);
        scoreMatrix *= transform2D::Translate(990, 650);
        RenderMesh2D(meshes["playerScore"], shaders["VertexColor"], scoreMatrix);
    }
    if (playerScore >= 20) {
        scoreMatrix = glm::mat3(1);
        scoreMatrix *= transform2D::Translate(1040, 650);
        RenderMesh2D(meshes["playerScore"], shaders["VertexColor"], scoreMatrix);
    }
    if (playerScore >= 30) {
        scoreMatrix = glm::mat3(1);
        scoreMatrix *= transform2D::Translate(1090, 650);
        RenderMesh2D(meshes["playerScore"], shaders["VertexColor"], scoreMatrix);
    }
    if (playerScore >= 40) {
        scoreMatrix = glm::mat3(1);
        scoreMatrix *= transform2D::Translate(1140, 650);
        RenderMesh2D(meshes["playerScore"], shaders["VertexColor"], scoreMatrix);
    }
    if (playerScore >= 50) {
        scoreMatrix = glm::mat3(1);
        scoreMatrix *= transform2D::Translate(1190, 650);
        RenderMesh2D(meshes["playerScore"], shaders["VertexColor"], scoreMatrix);
    }   
}

void Tema1::RenderEnvironment(float deltaTimeSeconds)
{
    glm::mat3 meadowMatrix = glm::mat3(1);
    glm::mat3 grassMatrix;
    meadowMatrix *= transform2D::Scale(21.5f, 1.2f);
    RenderMesh2D(meshes["meadow"], shaders["VertexColor"], meadowMatrix);

    if (grassAngularStepSign == 1) {
        grassAngularStep += deltaTimeSeconds;
        if (grassAngularStep >= M_PI / 12) {
            grassAngularStepSign = -1;
        }
    }
    else if (grassAngularStepSign == -1) {
        grassAngularStep -= deltaTimeSeconds;
        if (grassAngularStep <= -M_PI / 12) {
            grassAngularStepSign = 1;
        }
    }
    for (int i = 0; i <= 500; i++) {
        grassMatrix = glm::mat3(1);
        grassMatrix *= transform2D::Translate(i * 3, 50);
        grassMatrix *= transform2D::Rotate(grassAngles[i % grassAngles.size()]);
        if (i % 2 == 0) {
            grassMatrix *= transform2D::Rotate(grassAngularStep);
        }
        else {
            grassMatrix *= transform2D::Rotate(-grassAngularStep);
        }
        grassMatrix *= transform2D::Scale(1, 3);
        RenderMesh2D(meshes["grass"], shaders["VertexColor"], grassMatrix);
    }
}

void Tema1::RenderNightsky()
{
    glm::mat3 moonMatrix = glm::mat3(1);
    moonMatrix *= transform2D::Translate(1020, 610);
    moonMatrix *= transform2D::Scale(35, 35);
    RenderMesh2D(meshes["blackCircle"], shaders["VertexColor"], moonMatrix);

    moonMatrix = glm::mat3(1);
    moonMatrix *= transform2D::Translate(1000, 600);
    moonMatrix *= transform2D::Scale(35, 35);
    RenderMesh2D(meshes["moon"], shaders["VertexColor"], moonMatrix);

    glm::mat3 starMatrix = glm::mat3(1);
    starMatrix *= transform2D::Translate(940, 560);
    starMatrix *= transform2D::Scale(3, 3);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], starMatrix);

    for (int i = 0; i < stars.size(); i++) {
        starMatrix = glm::mat3(1);
        starMatrix *= transform2D::Translate(stars[i].first, stars[i].second);
        starMatrix *= transform2D::Scale(2, 2);
        RenderMesh2D(meshes["star"], shaders["VertexColor"], starMatrix);
    }
}


void Tema1::Update(float deltaTimeSeconds)
{
    RenderPlayerLives();
    RenderPlayerAmmo();
    RenderPlayerScore();
    RenderEnvironment(deltaTimeSeconds);
    RenderDuck(deltaTimeSeconds);
    RenderNightsky();

    timeOnScreen += deltaTimeSeconds;
    if (duckHit) {
        angle = 3 * M_PI / 2;
        GetDuckDirection(angle);
        if (translateY + 2 * triangleSide <= 0) {
            playerAmmo = 3;
            timeOnScreen = 0;
            GenerateInitialPosition();
            duckCount++;
            if (duckCount == 5) {
                speedFactor++;
                duckCount = 0;
            }
            duckHit = false;
        }
    }
    // A 3 second cooldown before game resets
    else if (playerLives == 0 && timeOnScreen < 3) {
        return;
    }
    // Game resets
    else if (playerLives == 0 && timeOnScreen >= 3) {
        playerLives = 3;
        playerAmmo = 3;
        playerScore = 0;
        timeOnScreen = 0;
        if (duckCount == 5) {
            speedFactor++;
            duckCount = 0;
        }
    }
    // Duck escapes
    if (timeOnScreen > TIMEOUT || playerAmmo <= 0 && !duckHit) {
        angle = M_PI / 2;
        GetDuckDirection(angle);
        if (translateY - 2 * triangleSide >= resolution.y) {
            playerLives--;
            if (playerLives > 0) {
                playerAmmo = 3;
            }
            timeOnScreen = 0;
            GenerateInitialPosition();
            duckCount++;
            if (duckCount == 5) {
                speedFactor++;
                duckCount = 0;
            }
        }
    }
    // Duck hits the edge of the screen
    else if (!duckHit && CollisionDetected() ) {
        GetDuckDirection(angle);
    }
    translateX += 100 * speedFactor * translateXSign * deltaTimeSeconds * abs(cos(angle));
    translateY += 100 * speedFactor * translateYSign * deltaTimeSeconds * abs(sin(angle));
}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    if (mouseX > v1.x + translateX && mouseX < v2.x + translateX &&
        resolution.y - mouseY > v1.y + translateY && resolution.y - mouseY < v3.y + translateY) {
        cursorInDuckArea = true;
    }
    else {
        cursorInDuckArea = false;
    }
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    if (timeOnScreen < TIMEOUT && playerAmmo > 0 && !duckHit && button == GLFW_MOUSE_BUTTON_2) {
        playerAmmo--;
        if (cursorInDuckArea) {
            playerScore += 10;
            duckHit = true;
        }
    }
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
