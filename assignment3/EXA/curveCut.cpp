/*
*
*
File Name: curveCut.cpp
Assignment: Lab 2 Exercise B
*  Completed by: John Zhou
*  Submission Date: Sept 24, 2025
*/
#include "curveCut.h"

#include <iomanip>
#include <iostream>
using namespace std;
CurveCut::CurveCut(double x, double y, double width, double length,
                   double radius, const char* name)
    : Shape(Point(x, y), name),
      Rectangle(x, y, width, length, name),
      Circle(x, y, radius, name) {
  if (radius > std::min(width, length)) {
    cerr << "Error: radius must be <= min(width, length)" << endl;
    exit(EXIT_FAILURE);
  }
}


double CurveCut::area() const {
  return Rectangle::area() - 0.25 * Circle::area();
}


double CurveCut::perimeter() const {
  return Rectangle::perimeter() - 2 * Circle::get_radius() +
         0.5 * Circle::perimeter();
}

void CurveCut::display() const {
  cout << "CurveCut Name: " << getName() << "\n";
  cout << "X-coordinate: " << getOrigin().getx() << "\n";
  cout << "Y-coordinate: " << getOrigin().gety() << "\n";
  cout << "Width: " << get_side_a() << "\n";
  cout << "Length: " << get_side_b() << "\n";
  cout << "Radius of the cut: " << Circle::get_radius() << "\n";
}