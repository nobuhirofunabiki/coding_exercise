// (ref) https://sy-base.com/myrobotics/cpp/normal_distribution/
// compile: 
// $ g++ <filename>.cpp -I/usr/include/python2.7 -lpython2.7

#include <random>
#include <matplotlib-cpp/matplotlibcpp.h>

namespace plt = matplotlibcpp;

int main() {

    std::random_device seed;        // Instanciation of random value generator class
    std::mt19937 engine(seed());    // Mersenne Twister method
    // std::minstd_rand0 engine(seed());   // Linear Congruential Generators (LCGs)
    // std::ranlux24_base engine(seed());  // 

    double mean = 0.0;
    double sigma = 1.0;
    std::normal_distribution<> dist(mean, sigma);

    unsigned int n = 1000000;
    std::vector<double> list(n);

    for (size_t i = 0; i < n; i++) {
        list[i] = dist(engine);
    }

    std::vector<double> numbers, values;
    double range = mean + sigma*5.0;
    double step = 0.1;

    for (double i = -range; i <= range; i+=step) {
        int number = 0;
        for (const auto& el : list) {
            if (i-step/2.0 < el && el <= i+step/2.0) {
                ++number;
            } 
        }
        values.push_back(i);
        numbers.push_back(number);
    }

    plt::plot(values, numbers);
    plt::show();

    return 0;
}