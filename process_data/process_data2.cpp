#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For "accumulate"

int main() {
    std::vector<double> v {1.1, 2.0, 3.0, 4.0};
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    double ave = sum / v.size();

    std::cout << "Sum is " << sum << std::endl;
    std::cout << "Averate is " << ave << std::endl;
}