/*
*
*
File Name: square.cpp
Assignment: Lab 2 Exercise B
*  Completed by: John Zhou
*  Submission Date: Sept 24, 2025
*/
#include "square.h"

#include <iomanip>
#include <iostream>
using namespace std;

// Constructor
Square::Square(double x, double y, double side, const char* name)
    : Shape(Point(x, y), name), side_a(side) {}



double Square::get_side_a() const { return side_a; }
void Square::set_side_a(double side) { side_a = side; }

double Square::area() const { return side_a * side_a; }

double Square::perimeter() const { return 4 * side_a; }

void Square::display() const {
  cout << "Square Name: " << (getName()) << "\n";
  cout << fixed << setprecision(2);
  cout << "X-coordinate: " << getOrigin().getx() << "\n";
  cout << "Y-coordinate: " << getOrigin().gety() << "\n";
  cout << "Side a: " << side_a << "\n";
  cout << "Area: " << area() << "\n";
  cout << "Perimeter: " << perimeter() << "\n";
}
