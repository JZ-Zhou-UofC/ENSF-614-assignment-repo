/*
*
*
File Name: point.h
Assignment: Lab 2 Exercise B
*  Completed by: John Zhou
*  Submission Date: Sept 24, 2025
*/
#ifndef POINT_H
#define POINT_H


class Point {
private:
    double x;
    double y;
    int id;
    static int idCounter; // Static member to track all ID

public:
    Point(double x_val, double y_val);

    // Getters
    double getx() const;
    double gety() const;
    int getId() const;

    // Setters
    void setx(double x_val);
    void sety(double y_val);

    void display() const;
    //static to access the static member
    static int counter();
    double distance(const Point& other) const;
    //This can be static because this does not require an object of point
    static double distance(const Point& p1, const Point& p2);
};

#endif
