/*
*
*
File Name: shape.h
Assignment: Lab 2 Exercise B
*  Completed by: John Zhou
*  Submission Date: Sept 24, 2025
*/
#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

class Shape {
protected:
    Point origin;     
    char* shapeName;     

public:
    // shapeName is on heap
    // Constructor
    Shape(const Point& pt, const char* name);
    // Copy constructor
    Shape(const Shape& other);
    // Assignment operator
    Shape& operator=(const Shape& other);
    
    virtual ~Shape();

    // Getters
    const Point& getOrigin() const;
    const char* getName() const;

    void move(double dx, double dy);

    virtual void display() const;

  
    double distance(Shape& other);
    // Static function, does not require shape object
    static double distance(Shape& s1, Shape& s2);
};

#endif
