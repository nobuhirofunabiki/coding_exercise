// Example codes for "erase" function of std::vector 
#include <iostream>
#include <vector>

int main() {
    std::vector<unsigned int> v {5, 1, 6, 7, 2, 9, 3, 8};
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        if (*itr < 4) {
            v.erase(itr);
        }
    }

    for (auto& element : v) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
    return 0;
}