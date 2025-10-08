#include <iostream>
using namespace std;

// Template function with two parameters, but D is unused
template <class T, class D>
void printValue(T value) {
    cout << "Value: " << value << endl;
}
template <>
void printValue<int,double>(int value){
    cout << "Specialized int-double: " << value << endl;
}
template <>
void printValue<double,double>(double value){
    cout << "Specialized d-d: " << value << endl;
}

template <>
void printValue<double,int>(double value){
    cout << "Specialized d-int: " << value << endl;
}
int main() {
    printValue<int, double>(42);   // D = double, but not used
    printValue<double, double>(423.33); // D = char, not used
        printValue<double, int>(43.33); // D = char, not used
    return 0;
}
