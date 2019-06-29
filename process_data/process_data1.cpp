#include <iostream>
#include <vector>
#include <algorithm>

struct data_example {
    std::vector<unsigned int> stamp;
    std::vector<unsigned int> data;
} data_example_t;

int main() {
    data_example_t.stamp = std::vector<unsigned int> {1, 2, 2, 2, 3, 3, 4, 5, 5, 5};
    data_example_t.data  = std::vector<unsigned int> {4, 5, 6, 7, 8, 9, 9, 8, 2, 4};
    std::vector<unsigned int> temp = data_example_t.stamp;
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
     
    for (auto itr = temp.begin(); itr != temp.end(); itr++) {
        std::cout << *itr << ", ";
    }
    std::cout << "end\n";

    for (auto itr = temp.begin(); itr != temp.end(); itr++) {
        auto bounds = std::equal_range(data_example_t.stamp.begin(), data_example_t.stamp.end(), *itr);
        std::cout << "Bounds from " << std::distance(data_example_t.stamp.begin(), bounds.first);
        std::cout << " to " << std::distance(data_example_t.stamp.begin(), --bounds.second) << std::endl;
    }
}

