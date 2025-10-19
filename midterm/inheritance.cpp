#include <iostream>
using namespace std;
class A {
public:
    A(int x) { cout << "a constructed with " << x << "\n"; }
};

class B: public A{
public:
    B(int x) :A(x){ cout << "B constructed with " << x << "\n"; }
};

class C : virtual public B {
public:
    C(int x) : B(x) { cout << "C constructed\n"; }
};

class D : virtual public B {
public:
    D(int x) : B(x) { cout << "D constructed\n"; }
};

class E : public C, public D {
public:
    int e;
    E(int a, int b, int c)
        : B(a), C(b), D(c), e(100) { 
        cout << "E constructed\n"; 
    }
};

class F : public E {
public:
    int f;
    F(int a, int b, int c, int d)
        : B(d), E(a,b,c), f(999) { 
        cout << "F constructed\n"; 
    }
};

int main() {
    F obj(1,2,3,4);
    return 0;
}
