#include <iostream>
using namespace std;

class A {
public:
    int a1 = 1;
protected:
    int a2 = 2;
private:
    int a3 = 3;
};

class C : private A {
public:
    int c1 = 10;
    void funC();
protected:
    int c2 = 20;
private:
    int c3 = 30;
};

class D : public C {
public:
    int d1 = 100;
    void funD();
protected:
    int d2 = 200;
private:
    int d3 = 300;
};

void C::funC() {
    cout << "Inside funC() --- accessible members:\n";

    cout << "  c1 = " << c1 << endl; // ✅ own public
    cout << "  c2 = " << c2 << endl; // ✅ own protected
    cout << "  c3 = " << c3 << endl; // ✅ own private

    // a1 and a2 were inherited from A privately
    cout << "  a1 = " << a1 << " (inherited privately from A)\n"; // ✅ allowed inside C
    cout << "  a2 = " << a2 << " (inherited privately from A)\n"; // ✅ allowed inside C

    // a3 is private in A — not accessible
    // cout << a3; // ❌ ERROR: ‘int A::a3’ is private within this context

    // d1, d2, d3 belong to D (derived class)
    // cout << d1; // ❌ ERROR: C cannot see members of D

    cout << "(C cannot access D’s members like d1, d2, d3)\n\n";
}

void D::funD() {
    cout << "Inside funD() --- accessible members:\n";

    cout << "  d1 = " << d1 << endl; // ✅ own public
    cout << "  d2 = " << d2 << endl; // ✅ own protected
    // cout << d3; // ❌ private in D, accessible though because it’s own class
    cout << "  d3 = " << d3 << " (own private member)\n";

    cout << "  c1 = " << c1 << endl; // ✅ inherited public from C
    cout << "  c2 = " << c2 << endl; // ✅ inherited protected from C
    // cout << c3; // ❌ private in C

    // Because C privately inherited A, D can’t access A’s members directly
    // cout << a1; // ❌ not accessible
    // cout << a2; // ❌ not accessible

    cout << "(D cannot access A’s a1 or a2 because of private inheritance in C)\n";
}

int main() {
    D obj;
    obj.funC();  // inherited from C
    obj.funD();
}
