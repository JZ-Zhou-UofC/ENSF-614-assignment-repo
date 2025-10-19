class A {
    int x;
public:
    A(int x) : x(x) {}
    int get_x() const { return x; }
};

class B {
    A y;                // A is a *member*, not a pointer
public:
    B(int b);
    A get_A() const { return y; }
};
class C {
    B* z;        // Aggregation with B
public:
    C(B* b);
    const B* get_B() const;
};


class D {
    C* w;        // Aggregation with C
public:
    D(int d);

};

B::B(int b):y(b){

}

C::C(B*b):z(b){

}

D::D(int d){
    B* b = new B(d);
    w = new C(b);
}