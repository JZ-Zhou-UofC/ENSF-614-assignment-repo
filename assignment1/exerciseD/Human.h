/*
*
*
File Name: Human.H
Assignment: Lab 1 Exercise D
*  Completed by: John Zhou
*  Submission Date: Sept 17, 2025
*/
#ifndef HUMAN_H
#define HUMAN_H

#include "Point.h"

class Human {
protected:
    Point location;   // Location of an object of Human on a Cartisian Plain
    char *name;       // Human's name

public:
    // Constructor 

    Human(const char* nam = "", double x = 0, double y = 0);

    //the name will be created in the run time. Copy constructor, assignment operater and destructor are needed
    Human(const Human& other);


    Human& operator=(const Human& rhs);


    ~Human();

    // this getter should not have the ability to change anything inside the class
    // this should return a const char pointer for safety.
    const char* get_name() const;
    Point get_point() const;

    
    void set_name(const char* nam);

 
    void display() const;
};

#endif
