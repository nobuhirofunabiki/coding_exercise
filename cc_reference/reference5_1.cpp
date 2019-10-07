// (ref) https://www.geeksforgeeks.org/references-in-c/

#include <iostream>

int &function() {
    static int x = 10;
    return x;
}

int main() {
    function() = 30;
    std::cout << function() << std::endl;

    auto a = function();
    std::cout << "a = " << a << std::endl;

    return 0;
}