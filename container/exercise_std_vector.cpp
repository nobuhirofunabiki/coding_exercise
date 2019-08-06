// Example codes for std::vector 
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<unsigned int> v {1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 6};

    // -----------------------------------------------//
    // Example of "find" function use for "vector"    //
    // -----------------------------------------------//

    std::cout << "===\n" << "Example of find function\n" << "===\n";
    unsigned int v_search = 3;
    auto itr_find = std::find(v.begin(), v.end(), v_search);
    if (itr_find != v.end()) {
        size_t index_find = std::distance(v.begin(), itr_find);
        std::cout << index_find << std::endl;
    }
    else {
        std::cout << "The element is not found in the vector" << std::endl;
    }
    std::cout << "\n";


    // -------------------------------------------------//
    // Example of "equal_range" function                //
    // -------------------------------------------------// 

    std::cout << "===\n" << "Example of equal_range function\n" << "===\n";
    auto bounds = std::equal_range(v.begin(), v.end(), v_search);
    std::cout << "Bounds at positions " << std::distance(v.begin(), bounds.first);
    std::cout << " and " << std::distance(v.begin(), --bounds.second) << std::endl;
    std::cout << "\n";


    // -------------------------------------------------//
    // Range-based for (since C++11 )                   //
    // -------------------------------------------------// 

    std::cout << "===\n" << "Example of range-based for (since C+11)\n" << "===\n";

    // "for" statement after C++03
    std::cout << "for statement since C++03" << std::endl;
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        std::cout << *itr << ' ';
    }
    std::cout << "\n";

    // "for" statement after C++11
    std::cout << "for statement since C++11" << std::endl;
    for (auto itr : v) {
        std::cout << itr << ' ';
    }
    std::cout << "\n\n";


    // -------------------------------------------------//
    // Example codes for "erase" function               //
    // -------------------------------------------------// 

    std::cout << "===\n" << "Example of erase function\n" << "===\n";

    std::vector<unsigned int> v_copy = v;

    // Erase the 6th element
    v_copy.erase(v_copy.begin()+5);
    std::cout << "The 6th element is erased" << "\n";
    for (auto itr : v_copy) {
        std::cout << itr << " ";
    }
    std::cout << "\n";

    // Erase the first 3 elements
    v_copy.erase(v_copy.begin(), v_copy.begin()+3);
    std::cout << "The first 3 elements are erased" << "\n";
    for (auto itr : v_copy) {
        std::cout << itr << " ";
    }
    std::cout << "\n";


    return 0;
}