#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* storageM;
    int lengthM;

public:
    // Constructor from int
    Text(int n) {
        if (n <= 1) {
            cerr << "Length must be > 1" << endl;
            exit(1);
        }
        lengthM = n;
        storageM = new char[lengthM];
        for (int i = 0; i < lengthM; i++) {
            storageM[i] = '\0';  // initialize to null character
        }
    }

    // Constructor from C-string
    Text(const char* s) {
        lengthM = strlen(s) + 1;
        storageM = new char[lengthM];
        strcpy(storageM, s);
    }

    // Copy constructor
    Text(const Text& other) {
        lengthM = other.lengthM;
        storageM = new char[lengthM];
        strcpy(storageM, other.storageM);
    }

    // Assignment operator
    Text& operator=(const Text& other) {
        if (this != &other) {
            delete[] storageM;
            lengthM = other.lengthM;
            storageM = new char[lengthM];
            strcpy(storageM, other.storageM);
        }
        return *this;
    }

    // Destructor
    ~Text() {
        delete[] storageM;
    }

    // Subscript operators
    char& operator[](int index) {
        return storageM[index];
    }

    const char& operator[](int index) const {
        return storageM[index];
    }

    // Input operator (friend to access private members)
    friend istream& operator>>(istream& in, Text& t) {
        in >> t.storageM;
        return in;
    }

    // Optional: print the whole text (not required for your main)
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.storageM;
        return out;
    }
};
