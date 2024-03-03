#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <array>
#include <vector>

// klasa definiujaca wskazniki do punktow
class Point3D {
public:
    Point3D() = default;                            // konstruktor domyslny
    Point3D(double xyz);                            // konstruktor z argumentem bedacym wspolrzedna kazdego punktu wynoszaca xyz
    Point3D(std::array<double, 3> coordinates);     // konstruktor z argumentem bedacym wpolrzednymi {x,y,z}
    void displayCoordinates() const;                // metoda wypisujaca punkty
    static int DISPLAY_PRESITION;                   // ustalenie stalej precyzji

private:
    friend class VPointCloud;                       // zaprzyjaznienie klasy VPointCloud z ta klasa
    std::array<double, 3> coordinates_;             // zmienna prywatna klasy opisujaca koordynaty (wspolrzedne)
};


// klasa definiujca chmure punktow
class VPointCloud {
public:
    void addPoint(std::array<double, 3> coordinates);// metoda dodajaca wskaznik do punktu do chmury ze wspolrzednymi postaci {x,y,z}
    void addPoint(Point3D* point);                   // metoda dodajaca wskaznik do punktu przyjmujaca wskaznik na obiekt klasy Point3D
    void add(const VPointCloud& vPointCloud);        // metoda dodajaca punkty z chmury do chmury
    size_t count() const;                            // metoda zwracajaca rozmiar wektora
    Point3D geoCentre() const;                       // metoda zwracajaca punkt bedacy srodkiem geometrycznym
    void displayPoints() const;                      // metoda wyswietlajaca chmure punktow
    Point3D* getCopyPoint(size_t i);                 // metoda zwracajaca wspaznik do kopii punktu

private:
    std::vector<Point3D*> wsk_to_points_;            // wektor wskaznikow do punktow
    // static size_t count_;                            // zmienna przechowujaca rozmiar wektora
};

#endif
