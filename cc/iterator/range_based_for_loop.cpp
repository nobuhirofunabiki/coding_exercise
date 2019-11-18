#include <iostream>
#include <vector>
#include <map>

int main() {

    // Test1 ---------------------------------------------------
    std::cout << "Test-1" << std::endl;

    std::vector<int> v = {0, 1, 2, 3, 4};

    std::cout << "Example-1 (access by const reference)" << std::endl;
    for (const int& i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Example-2 (access by value)" << std::endl;
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Example-3 (access by forwarding reference)" << std::endl;
    for (auto&& i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Example-4 (the initializer can be an array)" << std::endl;
    int a[] = {0, 1, 2, 3, 4};
    for (int j : a) {
        std::cout << j << " ";
    }
    std::cout << "\n\n";

    // Test2 ----------------------------------------------------
    std::cout << "Test-2" << std::endl;
    std::cout << "Range-based-for-loop for map" << std::endl;

    std::map<int, std::string> m;
    m[0] = "test0";
    m[1] = "test1";
    m[2] = "test2";
    for (auto&& [first, second] : m) {
        std::cout << first << " : " << second << "\n";
    }
    std::cout << "\n";

    // Test3 ----------------------------------------------------
    std::cout << "Test-3" << std::endl;
    std::cout << "Change values in a container through range-based-for-loop" << std::endl;
    
    std::vector<int> v2 = {1, 2, 3, 4, 5};
    for (auto i : v2) {i = 1;}
    for (auto i : v2) {std::cout << i << " ";}
    std::cout << "\n";

    std::vector<int> v3 = {1, 2, 3, 4, 5};
    for (auto& i : v3) {i = 1;}
    for (const auto& i : v3) {std::cout << i << " ";}
    std::cout << "\n";

    std::vector<int> v4 = {1, 2, 3, 4, 5};
    for (auto&& i : v3) {i = 1;}
    for (const auto& i : v3) {std::cout << i << " ";}
    // Invalid syntax
    // for (const auto&& i : v3) {std::cout << i << " ";}
    std::cout << "\n";

    // Test4 ----------------------------------------------------
    std::cout << "Test-4" << std::endl;
    std::cout << "Erase values in a vector container through range-based-for-loop" << std::endl;

    std::vector<int> v5 {1, 2, 3, 4, 5};
    unsigned int counter = 0;
    for (auto&& i : v5) {
        if (i == 2) {
            v5.erase(v5.begin()+counter);
        }
        counter += 1;
    }
    for (const auto& i : v5) {
        std::cout << i << "\n";
    }
    std::cout << "\n";

    // Test5 ----------------------------------------------------
    std::cout << "Test-5" << std::endl;
    std::cout << "Erase values in a map container through range-based-for-loop" << std::endl;

    std::map<int, std::string> m2;
    m2[0] = "test0";
    m2[1] = "test1";
    m2[2] = "test2";
    m2[3] = "test3";
    m2[4] = "test4";

    unsigned int counter2 = 0;
    for (auto&& [i, j] : m2) {
        if (i == 2) {
            auto itr = m2.find(i);
            m2.erase(itr);
            // m2.erase(m2.begin()+counter2); // This does not work.
        }
        counter2 += 1;
    }
    for (const auto& [i,j] : m2) {
        std::cout << i << " : " << j << "\n";
    }

    return 0;
}