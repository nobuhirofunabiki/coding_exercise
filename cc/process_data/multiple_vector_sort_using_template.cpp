#include <iostream>
#include <vector>
#include <algorithm> // For "sort"
#include <numeric> // For "iota"

template <class T1, class T2>
void sort2Vectors(std::vector<T1> &av, std::vector<T2> &bv) {
    int n = av.size();
    std::vector<T1> p(n), av_temp(n);
    std::vector<T2> bv_temp(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](T1 a, T1 b) {return av[a] < av[b];});
    for (int itr = 0; itr < n; itr++) {
        av_temp[itr] = av[p[itr]];
        bv_temp[itr] = bv[p[itr]];
    }
    av = av_temp;
    bv = bv_temp;
}

int main() {
    std::vector<int> a = {1, 3, 4, 2, 5};
    std::vector<double> b = {1.1, 2.1, 3.1, 4.1, 5.1};
    std::cout << "Before sorting" << std::endl;
    for (int itr = 0; itr < a.size(); itr++) {
        std::cout << "a: " << a[itr] << "\t";
        std::cout << "b: " << b[itr] << "\n";
    }
    sort2Vectors<int, double>(a, b);
    std::cout << "After sorting" << std::endl;
    for (int itr = 0; itr < a.size(); itr++) {
        std::cout << "a: " << a[itr] << "\t";
        std::cout << "b: " << b[itr] << "\n";
    }
}