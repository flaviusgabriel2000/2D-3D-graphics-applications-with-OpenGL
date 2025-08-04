#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace Object2Dim
{
    Mesh* CreateSquare(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateTriangle(const std::string& name, glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 color);
    Mesh* CreateRectangle(const std::string& name, glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4, glm::vec3 color, bool fill = false);
    Mesh* CreateCircle(const std::string& name, double x, double y, glm::vec3 color, int no_vertices);
}
