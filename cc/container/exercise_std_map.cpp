#include <iostream>
#include <map>

int main(int argc, char** argv) {
    
    // Simple test
    std::map<unsigned int, std::string> map_temp;

    switch (1) {
        case 0 : {
            map_temp[0] = "test0";
            map_temp[1] = "test1";
            map_temp[2] = "test2";
        } break;

        case 1 : {
            map_temp.insert(std::pair<unsigned int, std::string>(0, "temp0"));
            map_temp.insert(std::pair<unsigned int, std::string>(1, "temp1"));
            map_temp.insert(std::pair<unsigned int, std::string>(2, "temp2"));
        } break;

        default : {
            std::cout << "Wrong argument" << std::endl;
            return 0;
        } break;
    }

    auto itr_1 = map_temp.begin();
    auto itr_2 = std::next(map_temp.begin());
    map_temp.erase(itr_1, itr_2);

    // for (auto itr = map_temp.begin(); itr != map_temp.end(); itr++) {
    //     std::cout << "No." << itr->first << " : " << itr->second << std::endl;
    // }

    std::cout << "Range-based 'for' of map" << std::endl;
    for (auto itr : map_temp) {
        std::cout << "No." << itr.first << " : " << itr.second << std::endl;
    }

    // Nested structure of map
    std::map<unsigned int, std::map<unsigned int, std::string>> map_nested;

    map_nested[0].insert(std::pair<unsigned int, std::string>(0, "temp0"));
    map_nested[0].insert(std::pair<unsigned int, std::string>(1, "temp1"));
    map_nested[0].insert(std::pair<unsigned int, std::string>(2, "temp2"));
    map_nested[1].insert(std::pair<unsigned int, std::string>(3, "temp3"));
    map_nested[1].insert(std::pair<unsigned int, std::string>(4, "temp4"));
    map_nested[2].insert(std::pair<unsigned int, std::string>(5, "temp5"));
    map_nested[2].insert(std::pair<unsigned int, std::string>(6, "temp6"));
    // map_nested[3].insert(std::pair<unsigned int, std::string>(7, "temp7"));

    for (auto itr = map_nested.begin(); itr != map_nested.end(); itr++) {
        std::cout << "Group : " << itr->first << std::endl;
        for (auto itr_child = (itr->second).begin(); itr_child != (itr->second).end(); itr_child++) {
            std::cout << "\t No." << itr_child->first << " : " << itr_child->second << std::endl;
        }
    }

    // How to access to the last element
    // .end() is the iterator which expresses the 

    auto last_itr = map_nested.end();
    last_itr--;
    auto last_itr_child = (last_itr->second).end();
    last_itr_child--;

    std::cout << last_itr_child->first << std::endl;

    return 0;
}