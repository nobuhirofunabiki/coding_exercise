#include <iostream>

int main() {
    std::string str = "/hoge/foo";
    int index_start;
    int index_end;
    int count = 0;
    for (int i=0; i<str.size(); i++) {
        if (str.substr(i,1) == "/") {
            if (count == 0) {index_start = i+1; count++;}
            else if (count == 1) {index_end = i-1;}
        }
    }
    int str_length = index_end - index_start + 1;
    std::cout << str.substr(index_start, str_length) << std::endl;
    return 0;
}