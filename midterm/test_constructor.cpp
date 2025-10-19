#include <iostream>
#include <string>
using namespace std;

class A {
    int value;
public:
    A(int x) : value(x) { 
        cout << "A constructed with value = " << value << "\n"; 
    }

    void showValue() const {
        cout << "[A] value = " << value << "\n";
    }

    void setValue(int x) {
        cout << "[A] updating value to " << x << "\n";
        value = x;
    }
};

class B : virtual public A {
public:
    B() : A(0) { 
        cout << "B constructed\n"; 
    }

    void processB() {
        cout << "[B] processing in B\n";
        setValue(100);  // call A's function
    }
};

class C : virtual public A {
public:
    C() : A(0) { 
        cout << "C constructed\n"; 
    }

    void processC() {
        cout << "[C] processing in C\n";
        setValue(200);  // call A's function
    }
};

class D : public B, public C {
public:
    D() : A(4) {
        cout << "D constructed\n";
    }

    void processD() {
        cout << "[D] combining results from B and C\n";
        processB();
        processC();
    }
};

class E : public D {
public:
    E(int x) : A(x){
        cout << "E constructed\n";
    }

    void processE() {
        cout << "[E] extending behavior of D\n";
        processD();      // use D's behavior
        setValue(999);   // directly touch A
        showValue();
    }
};

int main() {
    E e(42);       // Construct E with initial value
    cout << "\n--- Running functions ---\n";
    e.showValue(); // From A
    e.processB();  // From B
    e.processC();  // From C
    e.processD();  // From D
    e.processE();  // From E
}
