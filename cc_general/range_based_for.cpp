// "for" statement to deal with arrays and containers easily

#include <iostream>
#include <vector>

int main() {

    std::vector<int> vector_ = {1, 2, 3, 4};

    vector_.push_back(5);

    // "for" statement after C++03
    for (auto itr = vector_.begin(); itr != vector_.end(); itr++) {
        std::cout << *itr << '\n';
    }

    // "for" statement after C++11
    for (auto itr : vector_) {
        std::cout << itr << '\n';
    }

    return 0;
}

