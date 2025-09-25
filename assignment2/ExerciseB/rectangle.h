/*
*
*
File Name: rectangle.cpp
Assignment: Lab 2 Exercise B
*  Completed by: John Zhou
*  Submission Date: Sept 24, 2025
*/
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "square.h"

class Rectangle : public Square
{
private:
    double side_b;

public:
    Rectangle(double x, double y, double side_a, double side_b, const char *name);

    Rectangle(const Rectangle &other);
    Rectangle &operator=(const Rectangle &other);

    double get_side_b() const;
    void set_side_b(double side);

    double area() const override;
    double perimeter() const override;
    void display() const override;
};

#endif
