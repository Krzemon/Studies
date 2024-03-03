#include "Polygon.h"
#include <iostream>

Polygon::Polygon() : name(""), numVertices(0), vertices(nullptr) {}

Polygon::Polygon(const std::string& n) : name(n), numVertices(0), vertices(nullptr) {}

Polygon::Polygon(const std::string& n, std::initializer_list<Point> verts) : name(n), numVertices(verts.size()) {
    vertices = new Point[numVertices];
    int i = 0;
    for (const auto& vert : verts) {
        vertices[i++] = vert;
    }
}

Polygon::~Polygon() {
    delete[] vertices;
}

template<typename... Args>
Polygon::Polygon(const std::string& n, Args&&... verts) : name(n), numVertices(sizeof...(verts)) {
    vertices = new Point[numVertices];
    int i = 0;
    (vertices[i++] = std::forward<Args>(verts), ...);
}

void Polygon::SetName(const std::string& n) {
    name = n;
}

void Polygon::SetNewVertices(int numVert, const Point* verts) {
    delete[] vertices;
    numVertices = numVert;
    vertices = new Point[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = verts[i];
    }
}

Point* Polygon::GetVertices() {
    return vertices;
}

// void Polygon::SetVertices(int numVert, const Point* verts) {
//     SetNewVertices(numVert, verts);
// }

void SetVertices(int numVert, std::string name, double xVal, double yVal){
    Point point(name, xVal, yVal);
    const Point* point_wsk = &point;
    SetNewVertices(numVert, point_wsk);
}


void Polygon::Presentation() {
    std::cout << "Polygon " << name << " with " << numVertices << " vertices:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        vertices[i].Presentation();
    }
    std::cout << std::endl;
}
