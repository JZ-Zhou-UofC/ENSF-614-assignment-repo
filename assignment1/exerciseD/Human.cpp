/*
*
*
File Name: Human.cpp
Assignment: Lab 1 Exercise D
*  Completed by: John Zhou
*  Submission Date: Sept 17, 2025
*/
#include "Human.h"
#include <cstring>
#include <iostream>
using namespace std;

Human::Human(const char *nam, double x, double y)
    : location(x, y)
{
    name = new char[strlen(nam) + 1];
    strcpy(name, nam);
}

Human::Human(const Human &other)
    : location(other.location)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

Human &Human::operator=(const Human &rhs)
{
    if (this != &rhs)
    {
        location = rhs.location;

        delete[] name;
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }
    return *this;
}

Human::~Human()
{
    delete[] name;
}

const char *Human::get_name() const { return name; }
Point Human::get_point() const { return location; }

void Human::set_name(const char *nam)
{
    delete[] name;
    name = new char[strlen(nam) + 1];
    strcpy(name, nam);
}

void Human::display() const
{
    cout << "Human Name: " << name
         << "\nHuman Location: "
         << location.get_x() << " ,"
         << location.get_y() << ".\n"
         << endl;
}
