// quux.h
#include <stdlib.h>
#include <iostream>
using namespace std;
class Quux {
protected:
    char *quux;
public:
    Quux(const char* q);
    ~Quux() { delete [] quux; }
    Quux(const Quux& src);
};

// quux.cpp
Quux::Quux(const char* q): quux(new char[strlen(q)+1]) {
    if (quux == nullptr) {
        cout << "No memory available...";
        exit(1);
    }
    strcpy(this->quux, q);
}
// bar.h
class Bar : public Quux {
protected:
    char *bar;
public:
    Bar(const char* b, const char* q);
    ~Bar() { delete [] bar; }
};
// bar.cpp
Bar::Bar(const char* b, const char* q): Quux(q), bar(new char[strlen(b)+1]) {
    if (bar == nullptr) {
        cout << "No memory available...";
        exit(1);
    }
    strcpy(this->bar, b);
}

Bar::Bar(const Bar& other):Quux(other){
    bar = new char[strlen(other.bar)+1];
    if (bar == nullptr) {
        cout << "No memory available...";
        exit(1);
    }
    strcpy(this->bar, other.bar);
}