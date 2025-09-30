/*
*
*
File Name: point.cpp
Assignment: Lab 2 Exercise B
*  Completed by: John Zhou
*  Submission Date: Sept 24, 2025
*/
#include "point.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int Point::idCounter = 1000;  
// Constructor
Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {
    idCounter ++;
    id=idCounter;
}


// Getters
double Point::getx() const { return x; }
double Point::gety() const { return y; }
int Point::getId() const { return id; }

// Setters
void Point::setx(double x_val) { x = x_val; }
void Point::sety(double y_val) { y = y_val; }


void Point::display() const {
    cout << fixed << setprecision(2);
    cout << "X-coordinate: " << x << "\n";
    cout << "Y-coordinate: " << y << "\n";
}

int Point::counter() {
    return idCounter -1000;
}

double Point::distance(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

// Static distance (between any two points)
double Point::distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}
