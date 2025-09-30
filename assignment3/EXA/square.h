/*
*
*
File Name: square.h
Assignment: Lab 2 Exercise B
*  Completed by: John Zhou
*  Submission Date: Sept 24, 2025
*/
#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape
{
private:
    double side_a;

public:
    // Constructor
    Square(double x, double y, double side, const char *name);

    double get_side_a() const;
    void set_side_a(double side);


   virtual double area() const ;
    virtual double perimeter() const ;
    virtual void display() const ;
};

#endif
