/*
*
*
File Name: shape.cpp
Assignment: Lab 2 Exercise B
*  Completed by: John Zhou
*  Submission Date: Sept 24, 2025
*/
#include "shape.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

// Constructor
Shape::Shape(const Point& pt, const char* name) : origin(pt) {

        shapeName = new char[strlen(name) + 1];
        strcpy(shapeName, name);

}

Shape::Shape(const Shape& other) : origin(other.origin) {
    if (other.shapeName) {
        shapeName = new char[strlen(other.shapeName) + 1];
        strcpy(shapeName, other.shapeName);
    } else {
        shapeName = nullptr;
    }
}

// Assignment operator
Shape& Shape::operator=(const Shape& other) {
    if (this != &other) {
        origin = other.origin;

        delete[] shapeName;
        if (other.shapeName) {
            shapeName = new char[strlen(other.shapeName) + 1];
            strcpy(shapeName, other.shapeName);
        } else {
            shapeName = nullptr;
        }
    }
    return *this;
}
// Destructor
Shape::~Shape() {
    delete[] shapeName;
}

// Getters
const Point& Shape::getOrigin() const {
    return origin; 
}

const char* Shape::getName() const {
    return shapeName;
}

void Shape::move(double dx, double dy) {
    origin.setx(origin.getx() + dx);
    origin.sety(origin.gety() + dy);
}


void Shape::display() const {
    cout << "Shape Name: " << (shapeName ? shapeName : "Unnamed") << "\n";
    cout << fixed << setprecision(2);
    cout << "X-coordinate: " << origin.getx() << "\n";
    cout << "Y-coordinate: " << origin.gety() << "\n";
}

double Shape::distance(Shape& other) {
    return origin.distance(other.getOrigin());
}


double Shape::distance(Shape& s1, Shape& s2) {
    return Point::distance(s1.getOrigin(), s2.getOrigin());
}
