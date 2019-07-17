#include <iostream>
#include <algorithm>
#include <vector>

void hampelOutlierRejection(std::vector<double> data_input);
double calculateMedian(std::vector<double> data_input);

int main(){
    std::vector<double> data_input {5.0, 4.0, 60.0, 4.5, 5.5, 5.2, 6.0};

    hampelOutlierRejection(data_input);
}


void hampelOutlierRejection(std::vector<double> data_input) {
    unsigned int data_size = data_input.size();

    std::vector<double> sorted_data = data_input;
    std::sort(sorted_data.begin(), sorted_data.end());

    // for (auto itr : sorted_data) {
    //     std::cout << itr << " ";
    // }
    // std::cout << "\n";

    double median_value;
    median_value = calculateMedian(sorted_data);
    // std::cout << "Median value is " << median_value << std::endl;

    std::vector<double> data_temp1 = sorted_data;
    std::vector<double> data_temp2 = sorted_data;
    std::vector<double> data_temp3;
    data_temp1.erase(data_temp1.begin());
    data_temp2.pop_back();

    // for (auto itr : data_temp1) {
    //     std::cout << itr << " ";
    // }
    // std::cout << "\n";

    // for (auto itr : data_temp2) {
    //     std::cout << itr << " ";
    // }
    // std::cout << "\n";

    for (int iData = 0; iData < data_temp1.size(); iData++) {
        data_temp3.push_back(data_temp1[iData] - data_temp2[iData]);
    }

    // for (auto itr : data_temp3) {
    //     std::cout << itr << " ";
    // }
    // std::cout << "\n";

    double dx = 3.0*calculateMedian(data_temp3);
    std::cout << "dx is " << dx << "\n";

}

double calculateMedian(std::vector<double> data_input) {
    std::sort(data_input.begin(), data_input.end());
    unsigned int data_size = data_input.size();
    double median_value;
    // Calculate median
    if (data_size % 2) {
        median_value = data_input[(data_size+1)/2-1];
    }
    else {
        median_value = (data_input[data_size/2-1]+data_input[data_size/2])/2;
    }
    return median_value;
}
