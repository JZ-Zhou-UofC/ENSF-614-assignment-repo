#include <iostream>
using namespace std;

// Template function with two parameters, but D is unused
template <class T, class D>
void printValue(T value) {
    cout << "Value: " << value << endl;
}

int main() {
    printValue<int, double>(42);   // D = double, but not used
    printValue<string, char>("Hello"); // D = char, not used
    return 0;
}
