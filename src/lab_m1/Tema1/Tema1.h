#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
     public:
        Tema1();
        ~Tema1();


        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void BuildDuck(int triangleSide);
        void CreatePlayerData();
        void CreateEnvironmentData();
        void GenerateInitialPosition();
        void GetDuckDirection(float angle);
        bool CollisionDetected();
        void RenderDuck(float deltaTimeSeconds);
        void RenderPlayerLives();
        void RenderPlayerAmmo();
        void RenderPlayerScore();
        void RenderEnvironment(float deltaTimeSeconds);
        void RenderNightsky();

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        glm::mat3 modelMatrix;
        glm::ivec2 resolution;
        float cxbody, cybody, cxuwing, cyuwing, cxlwing, cylwing;
        float triangleSide;
        float translateX, translateY;
        float wingAngularStep;
        float angle;
        float timeOnScreen;

        int translateXSign, translateYSign;
        int duckCount, speedFactor;
        int playerLives, playerAmmo, playerScore;

        glm::vec3 v1, v2, v3, v4; // Hitbox vertices
        bool cursorInDuckArea, duckHit;

        std::vector<float> grassAngles;
        float grassAngularStep;
        int grassAngularStepSign;

        std::vector<std::pair<float, float>> stars;
    };
}   // namespace m1
