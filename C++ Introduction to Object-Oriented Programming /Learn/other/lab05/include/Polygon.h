#ifndef POLYGON_H
#define POLYGON_H

#include <string>
#include <initializer_list>
#include "Point.h"

class Polygon {
private:
    std::string name;
    int numVertices;
    Point *vertices;

public:
    Polygon();
    Polygon(const std::string& n);
    Polygon(const std::string& n, std::initializer_list<Point> verts);
    Polygon(const std::string& n, int numVert, const Point* verts);

    template<typename... Args>
    Polygon(const std::string& n, Args&&... verts);
    void SetName(const std::string& n);
    void SetNewVertices(int numVert, const Point* verts);
    Point* GetVertices();  // Add this function declaration

    // Change the name of this function for consistency
    // void SetVertices(int numVert, const Point* verts);

	// poly3.SetVertices(1, "G", 45.1, 11.99);    
    void SetVertices(int numVert, std::string name, double xVal, double yVal);


    void Presentation();

    ~Polygon();
};

#endif
