/*
*
*
File Name: circle.cpp
Assignment: Lab 3 Exercise A
*  Completed by: John Zhou
*  Submission Date: oct 1st, 2025
*/
#include <iomanip>
#include <iostream>

#include "circle.h"
using namespace std;


const double Circle::pi = 3.141592653589793;
// Constructor
Circle::Circle(double x, double y, double r, const char *name)
    : Shape(Point(x, y), name), radius(r) {}

double Circle::get_radius() const { return radius; }
void Circle::set_radius(double r) { radius = r; }

double Circle::area() const { return radius* radius*pi; }

double Circle::perimeter() const { return 2*pi * radius; }

void Circle::display() const {
  cout << "Circle Name: " << (getName()) << "\n";
  cout << fixed << setprecision(2);
  cout << "X-coordinate: " << getOrigin().getx() << "\n";
  cout << "Y-coordinate: " << getOrigin().gety() << "\n";
  cout << "Radius: " << radius << "\n";
  cout << "Area: " << area() << "\n";
  cout << "Perimeter: " << perimeter() << "\n";
}
