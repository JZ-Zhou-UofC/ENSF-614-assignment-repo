/*
*
*
File Name: rectangle.cpp
Assignment: Lab 2 Exercise B
*  Completed by: John Zhou
*  Submission Date: Sept 24, 2025
*/
#ifndef CURVECUT_h
#define CURVECUT_h

#include "circle.h"
#include "rectangle.h"
class CurveCut : public Rectangle, Circle {
 public:
  CurveCut(double x, double y, double side_a, double side_b, double radius,
           const char* name);


  virtual double area() const override;
  virtual double perimeter() const override;
  virtual void display() const override;
};

#endif
