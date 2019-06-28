// Example codes for std::vector 
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<unsigned int> v {1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    unsigned int v_search = 3;

    // Example of "find" function use for "vector"
    std::cout << "Example of find function" << std::endl;
    auto itr_find = std::find(v.begin(), v.end(), v_search);
    if (itr_find != v.end()) {
        size_t index_find = std::distance(v.begin(), itr_find);
        std::cout << index_find << std::endl;
    }
    else {
        std::cout << "The element is not found in the vector" << std::endl;
    }

    // Example of "equal_range" function
    std::cout << "Example of equal_range function" << std::endl;
    auto bounds = std::equal_range(v.begin(), v.end(), v_search);
    std::cout << "Bounds at positions " << std::distance(v.begin(), bounds.first);
    std::cout << " and " << std::distance(v.begin(), --bounds.second) << std::endl;

    return 0;
}