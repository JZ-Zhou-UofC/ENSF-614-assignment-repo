#include <iostream>
using namespace std;

class Foo {
 public:
  int* xM;
  Foo(int n);
 virtual  ~Foo();
 virtual  void fun1();
  void fun2();
};

void Foo::fun1() { cout << *xM << endl; }
Foo::Foo(int n) { xM = new int[n]; }
Foo::~Foo() { delete xM; }
void Foo::fun2() { (*xM)++; }

class Bar: public Foo {
 protected:
  int* yM;

 public:
  Bar(int n, int m);
  ~Bar();
  void fun1();
};

Bar::Bar(int n, int m): yM(new int [m]), Foo(n){ 
} 
Bar::~Bar() { 
delete yM; 
} 
void Bar::fun1() { 
cout << *xM << "" << *yM << endl; 
} 