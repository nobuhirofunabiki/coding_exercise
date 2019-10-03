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