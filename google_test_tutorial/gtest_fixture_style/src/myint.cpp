#include "myint.h"

MyInt::MyInt() {}

MyInt::MyInt(int num)
:num_(num)
{}

MyInt::~MyInt() {}

bool MyInt::isOdd() {
    return (num_ % 2) != 0 ? true : false;
}

bool MyInt::isEven() {
    return (num_ % 2) != 0 ? true : false; // Wrong
    // return (num_ % 2) == 0 ? true : false; // Correct
}

int MyInt::addTwoInts(int a, int b) {
    return a+b;
}


template <typename TYPE>
TYPE MyInt::addTwoValues(TYPE a, TYPE b) {
    return a+b;
}

double MyInt::addTwoDoubles(double a, double b) {
    // In order to run unittests for any template functions, 
    // they should be used somewhere in the class and instanciated as following.
    return addTwoValues<double>(a, b);
}