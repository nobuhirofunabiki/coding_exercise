// Sample cord to illustrate how to use reference
// (ref) https://www.geeksforgeeks.org/references-in-c/
// The basic cord

#include <iostream>

int main() {
    int x = 10;

    // ref is a reference to x
    // int& ref = x;
    int &ref = x;

    // The value of x is now changed to 20
    ref = 20;
    std::cout << "x = " << x << std::endl;

    // The value of x is now changed to 30
    x = 30;
    std::cout << "ref = " << ref << std::endl;

    return 0;
}