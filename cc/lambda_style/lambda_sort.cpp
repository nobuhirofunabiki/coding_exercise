#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int calculateSquare(const int x) {
    return std::pow(x,2);
}

int main() {
    std::vector<int> vec {1, -2, 0, 3, -3, 6, -5, 4};
    // std::vector<int> vec {0, 1, -2, 3, -3, 4, -5, 6}; \\ expected sorted vector
    
    std::cout << "Before sorting" << std::endl;
    for (const auto& v : vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    std::sort(
        vec.begin(),
        vec.end(),
        [](const int& x, const int& y) {return calculateSquare(x) < calculateSquare(y);}
    );

    std::cout << "After sorting" << std::endl;
    for (const auto& v : vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    return 0;
}
