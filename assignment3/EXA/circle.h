/*
*
*
File Name: circle.h
Assignment: Lab 3 Exercise A
*  Completed by: John Zhou
*  Submission Date: oct 1st, 2025
*/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : virtual public Shape {
 private:
  double radius;

 public:
  static const double pi;
  Circle(double x, double y, double radius, const char* name);
  Circle(double r, const Point& pt, const char* n) : Shape(pt, n), radius(r) {}

  double get_radius() const;
  void set_radius(double r);

  virtual double area() const;
  virtual double perimeter() const;
  virtual void display() const;
};

#endif
