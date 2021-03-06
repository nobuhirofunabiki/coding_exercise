#include <iostream>
#include <vector>
#include <algorithm> // For "sort"
#include <numeric> // For "iota"

void sort2vectors(std::vector<int> &av, std::vector<int> &bv) {
    int n = av.size();
    std::vector<int> p(n), av_temp(n), bv_temp(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int a, int b) {return av[a] < av[b];});
    for (int itr = 0; itr < n; itr++) {
        av_temp[itr] = av[p[itr]];
        bv_temp[itr] = bv[p[itr]];
    }
    av = av_temp;
    bv = bv_temp;
}

int main() {
    std::vector<int> a = {1, 3, 4, 2, 5};
    std::vector<int> b = {10, 20, 30, 40, 50};
    std::cout << "Before sorting" << std::endl;
    for (int itr = 0; itr < a.size(); itr++) {
        std::cout << "a: " << a[itr] << "\t";
        std::cout << "b: " << b[itr] << "\n";
    }
    sort2vectors(a, b);
    std::cout << "After sorting" << std::endl;
    for (int itr = 0; itr < a.size(); itr++) {
        std::cout << "a: " << a[itr] << "\t";
        std::cout << "b: " << b[itr] << "\n";
    }
}