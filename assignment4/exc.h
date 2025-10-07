#ifndef VEHICLE_HIERARCHY_H
#define VEHICLE_HIERARCHY_H

#include <string>
using namespace std;


class Moveable {
public:
    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual ~Moveable();
};


class Resizeable {
public:
    virtual void enlarge(int n) = 0;
    virtual void shrink(int n) = 0;
    virtual ~Resizeable();
};


class Vehicle : public Moveable, public Resizeable {
protected:
    string name;

public:
    Vehicle(const string& name);
    virtual void move();
    virtual ~Vehicle();
};

class Car : public Vehicle {
private:
    int seats;

public:
    Car(const string& name, int seats);
    void turn();
    // Implement abstract functions
    void forward() override;
    void backward() override;
    void enlarge(int n) override;
    void shrink(int n) override;
    void move() override;
};

#endif
