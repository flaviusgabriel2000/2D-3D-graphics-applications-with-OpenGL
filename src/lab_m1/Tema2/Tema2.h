#pragma once

#include "components/simple_scene.h"
#include "lab_m1/lab5/lab_camera.h"


namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
     public:
        struct ViewportArea
        {
            ViewportArea() : x(0), y(0), width(1), height(1) {}
            ViewportArea(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };
        Tema2();
        ~Tema2();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        Mesh* CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices);
        void RenderMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, implemented::Camera* camera, const glm::vec3& color = glm::vec3(1));
        void CreateTrack();
        void CreateTree();
        void CreateCar();
        void RenderCars(float deltaTimeSeconds, implemented::Camera *camera);
        void MoveCar(float &translateX, float &translateZ, int &index, std::vector<glm::vec3> &path, float deltaTimeSeconds);
        void RenderEnvironment(implemented::Camera *camera);
        bool IsOnTrack(glm::vec3 targetPoint);
        bool SameSide(glm::vec3 P1, glm::vec3 P2, glm::vec3 A, glm::vec3 B);
        bool IsPointInTriangle(glm::vec3 P, glm::vec3 A, glm::vec3 B, glm::vec3 C);
        bool CollisionDetected(glm::vec3 enemy, implemented::Camera* camera);

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        implemented::Camera *camera, *minimapCamera;
        glm::mat4 projectionMatrix, perspectiveMatrix, orthoMatrix;
        ViewportArea minimapArea;

        float orthoLeft, orthoRight, orthoBottom, orthoTop, zNearO, zFarO;
        float fov, aspect, zNearP, zFarP;

        std::vector<VertexFormat> trackVertices;
        std::vector<glm::vec3> outerVertices, innerVertices;
        std::vector<glm::ivec2> treesPositions;
        std::vector<std::vector<glm::vec3>> paths;
        std::vector<float> angles;
        float carAngularStep, carRadius = 1;
        float translateXCar_1, translateZCar_1, translateXCar_2, translateZCar_2, translateXCar_3, translateZCar_3;
        int indexCar_1 = 0, indexCar_2 = 12, indexCar_3 = 5;        
    };
}   // namespace m1
