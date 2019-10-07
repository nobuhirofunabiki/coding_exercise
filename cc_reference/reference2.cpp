// Sample cord to illustrate how to use reference
// (ref) https://www.geeksforgeeks.org/references-in-c/
// Modify the passed parameters in a function

#include <iostream>

// void swap(int& first, int& second) {
void swap(int &first, int &second) {
    auto temp = first;
    first = second;
    second = temp;
}

int main() { 
    int a = 10;
    int b = 20;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    swap(a,b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}