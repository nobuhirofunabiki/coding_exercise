// Sample cord to illustrate how to use reference
// (ref) https://www.geeksforgeeks.org/references-in-c/
// In For Each Loops to modify all objects and avoid copy of objects

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1,2,3,4};

    for (int &x : vec) {
        x = x + 5;
    }

    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (const auto &x : vec) {
        std::cout << x << " ";
    }

    return 0;
}