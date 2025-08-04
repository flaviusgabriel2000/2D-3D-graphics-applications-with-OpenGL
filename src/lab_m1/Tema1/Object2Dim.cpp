#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"
#include "lab_m1/Tema1/Object2Dim.h"


Mesh* Object2Dim::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = {0, 1, 2, 3};

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* Object2Dim::CreateTriangle(
    const std::string& name,
    glm::vec3 v1,
    glm::vec3 v2,
    glm::vec3 v3,
    glm::vec3 color)
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(v1, color),
        VertexFormat(v2, color),
        VertexFormat(v3, color),
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = {0, 1, 2};

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* Object2Dim::CreateRectangle(
    const std::string& name,
    glm::vec3 v1,
    glm::vec3 v2,
    glm::vec3 v3,
    glm::vec3 v4,
    glm::vec3 color,
    bool fill)
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(v1, color),
        VertexFormat(v2, color),
        VertexFormat(v3, color),
        VertexFormat(v4, color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = {0, 1, 2};

    if (!fill) {
        indices.push_back(3);
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        indices.push_back(3);
        indices.push_back(2);
        indices.push_back(1);
    }
    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* Object2Dim::CreateCircle(
    const std::string& name,
    double x,
    double y,
    glm::vec3 color,
    int no_vertices)
{
    std::vector<VertexFormat> vertices;
    for (int i = 0; i < no_vertices; i++) {
        vertices.push_back(VertexFormat(
            glm::vec3(x + cos(2 * M_PI * i / (float)no_vertices),
                      y + sin(2 * M_PI * i / (float)no_vertices), 0), 
            color));
    }

    std::vector<unsigned int> indices;
    for (int i = 0; i < no_vertices; i++) {
        indices.push_back(i);
    }

    Mesh* circle = new Mesh(name);
    circle->SetDrawMode(GL_TRIANGLE_FAN);
    circle->InitFromData(vertices, indices);
    return circle;
}
