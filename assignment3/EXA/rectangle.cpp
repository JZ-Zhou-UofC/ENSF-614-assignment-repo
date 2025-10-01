/*
*
*
File Name: rectangle.cpp
Assignment: Lab 2 Exercise B
*  Completed by: John Zhou
*  Submission Date: Sept 24, 2025
*/
#include "rectangle.h"
#include <iostream>
#include <iomanip>
using namespace std;

Rectangle::Rectangle(double x, double y, double side_a, double side_b, const char *name)
    : Shape(Point(x, y), name),Square(x, y, side_a, name), side_b(side_b) {}


double Rectangle::get_side_b() const
{
    return side_b;
}

void Rectangle::set_side_b(double side)
{
    side_b = side;
}

double Rectangle::area() const
{
    return get_side_a() * side_b;
}

double Rectangle::perimeter() const
{
    return 2 * (get_side_a() + side_b);
}

void Rectangle::display() const
{
    cout << "Rectangle Name: " << (getName()) << "\n";
    cout << fixed << setprecision(2);
    cout << "X-coordinate: " << getOrigin().getx() << "\n";
    cout << "Y-coordinate: " << getOrigin().gety() << "\n";
    cout << "Side a: " << get_side_a() << "\n";
    cout << "Side b: " << side_b << "\n";
    cout << "Area: " << area() << "\n";
    cout << "Perimeter: " << perimeter() << "\n";
}
