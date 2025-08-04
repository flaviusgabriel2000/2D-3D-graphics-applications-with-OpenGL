#pragma once

#include "components/simple_scene.h"
#include "lab_m1/lab5/lab_camera.h"


constexpr auto MAX_SPOTLIGHTS = 20;
constexpr auto MAX_POINTLIGHTS = 15;
constexpr auto MAX_DELETION_DISTANCE = 4;
constexpr auto MAX_PLAYER_ROTATION_ANGLE = 45;
constexpr auto MAX_COLLISION_TOLERANCE = 0.2f;


namespace m1
{
    class Tema3 : public gfxc::SimpleScene
    {
     public:
        Tema3();
        ~Tema3();
        enum ObjectType {LightingPole, Tree, Stone, Gift};
        struct RandomObject
        {
            RandomObject(float posX, float posZ, ObjectType type, bool collided, int index)
                : posX(posX), posZ(posZ), type(type), collided(collided), index(index) {}
            float posX;
            float posZ;
            ObjectType type;
            bool collided;
            int index;
        };

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        Mesh* CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices);
        void RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, Texture2D* texture = NULL, const glm::vec3& color = glm::vec3(1));
        void CreateHill();
        void CreatePlayer();
        void CreateTree();
        void CreateStone();
        void CreateLightingPole();
        void CreateGift();
        void RenderLightingPole(float distanceX, float distanceYZ, int index);
        void RenderTree(float distanceX, float distanceYZ, int index);
        void RenderStone(float distanceX, float distanceYZ);
        void RenderGift(float distanceX, float distanceYZ, int index);
        void RenderPlayerAndHill();
        void GenerateRandomObjects();
        void CheckCollision();

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        implemented::Camera *camera;
        glm::mat4 projectionMatrix;
        std::unordered_map<std::string, Texture2D*> mapTextures;
        const std::string sourceTextureDir = PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "textures");
        float fov, aspect, zNearP, zFarP;

        glm::ivec2 resolution = window->GetResolution();
        glm::vec2 texcoordShift = glm::vec2(0.0f, 0.0f);
        std::vector<RandomObject> randomObjects;

        float translateX = 0, translateYZ = 0, timer = 0, playerAngularStep = 0;
        int playerScore = 0;
        bool gameOver = false;

        glm::vec3 directionalLightDir = glm::vec3(0.0f, -1.0f, 0.0f);
        glm::vec3 spotLightPosition[MAX_SPOTLIGHTS], pointLightPosition[MAX_POINTLIGHTS], pointLightColors[MAX_POINTLIGHTS];
        unsigned int materialShininess = 30, spotLightsIndex = 0, pointLightsIndex = 0;
        float materialKd = 0.5f;
        float materialKs = 0.5f;
    };
}   // namespace m1
