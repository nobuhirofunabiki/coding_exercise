#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

template <typename TYPE_DATA, typename TYPE_STAMP>
void hampelOutlierRejection(std::vector<TYPE_DATA> data_input, 
                            std::vector<TYPE_STAMP> data_stamp,
                            std::vector<bool>& b_outlier_list);
template <typename TYPE_DATA, typename TYPE_STAMP>
void calculateLocalWindow(std::vector<TYPE_DATA> data_input, std::vector<TYPE_STAMP> data_stamp,
                          TYPE_STAMP half_window_length, unsigned int data_index,
                          std::vector<TYPE_DATA>& local_ref, std::vector<TYPE_DATA>& local_var);
template <typename TYPE>
TYPE calculateMedian(std::vector<TYPE> data_input);


int main(){
    std::vector<double> data_stamp {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<double> data_input {5.0, 4.0, 60.0, 4.5, 5.5, 5.2, 6.0, 70, 5.8};
    std::vector<bool> b_outlier_list(data_input.size(), false);

    hampelOutlierRejection(data_input, data_stamp, b_outlier_list);

    std::cout << "outlier list" << "\n";
    for (auto iOutlier : b_outlier_list) {
        std::cout << iOutlier << " ";
    }
    std::cout << "\n";
}


template <typename TYPE_DATA, typename TYPE_STAMP>
void hampelOutlierRejection(std::vector<TYPE_DATA> data_input, 
                            std::vector<TYPE_STAMP> data_stamp,
                            std::vector<bool>& b_outlier_list) {
    unsigned int data_size = data_input.size();

    std::vector<TYPE_STAMP> sorted_stamp = data_stamp;
    std::sort(sorted_stamp.begin(), sorted_stamp.end());

    TYPE_STAMP median_stamp;
    median_stamp = calculateMedian(sorted_stamp);

    std::vector<TYPE_STAMP> stamp_temp1 = sorted_stamp;
    std::vector<TYPE_STAMP> stamp_temp2 = sorted_stamp;
    std::vector<TYPE_STAMP> diff_stamp;
    stamp_temp1.erase(stamp_temp1.begin());
    stamp_temp2.pop_back();

    for (int iData = 0; iData < stamp_temp1.size(); iData++) {
        diff_stamp.push_back(stamp_temp1[iData] - stamp_temp2[iData]);
    }

    TYPE_STAMP half_window_length = 3.0*calculateMedian(diff_stamp);

    std::vector<TYPE_DATA> local_ref;
    std::vector<TYPE_DATA> local_var;

    for (int iData = 0; iData < data_size; iData++) {
        calculateLocalWindow(data_input, data_stamp, half_window_length, iData, local_ref, local_var);
    }

    for (int iData = 0; iData < data_size; iData++) {
        TYPE_DATA temp = std::fabs(data_input[iData] - local_ref[iData]) - 3.0*local_var[iData];
        if (temp > 0) {
            b_outlier_list[iData] = true;
        }
    }
}

template <typename TYPE_DATA, typename TYPE_STAMP>
void calculateLocalWindow(std::vector<TYPE_DATA> data_input, std::vector<TYPE_STAMP> data_stamp,
                          TYPE_STAMP half_window_length, unsigned int data_index,
                          std::vector<TYPE_DATA>& local_ref, std::vector<TYPE_DATA>& local_var) {

    // Index related to local window
    std::vector<int> index_local;
    std::vector<TYPE_STAMP> data_in_window;
    int data_size = data_stamp.size();
    for (int iData = 0; iData < data_size; iData++) {
        if (data_stamp[data_index] - half_window_length <= data_stamp[iData]
            && data_stamp[data_index] + half_window_length >= data_stamp[iData]) {
            index_local.push_back(iData);
            data_in_window.push_back(data_input[iData]);
        }
    }

    // Calculate local nominal data reference value
    TYPE_DATA local_ref_temp = calculateMedian(data_in_window);
    local_ref.push_back(local_ref_temp);

    std::vector<TYPE_DATA> diff_ref;
    for (int iData = 0; iData < data_in_window.size(); iData++) {
        diff_ref.push_back(std::fabs(data_in_window[iData] - local_ref_temp));
    }

    // Calculate local scale of natural variation
    local_var.push_back(1.4826*calculateMedian(diff_ref));
}

template <typename TYPE>
TYPE calculateMedian(std::vector<TYPE> data_input) {
    std::sort(data_input.begin(), data_input.end());
    unsigned int data_size = data_input.size();
    TYPE median_value;
    // Calculate median
    if (data_size % 2) {
        median_value = data_input[(data_size+1)/2-1];
    }
    else {
        median_value = (data_input[data_size/2-1]+data_input[data_size/2])/2;
    }
    return median_value;
}
