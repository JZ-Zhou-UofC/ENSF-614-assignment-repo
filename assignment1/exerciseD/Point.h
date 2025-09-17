/*
*
*
File Name: point.h
Assignment: Lab 1 Exercise D
*  Completed by: John Zhou
*  Submission Date: Sept 17, 2025
*/
#ifndef POINT_H
#define POINT_H

class Point
{
private:
    double x;
    double y;

public:
    Point(double a = 0, double b = 0);
    double get_x() const;
    double get_y() const;
    void set_x(double a);
    void set_y(double a);
};

#endif
