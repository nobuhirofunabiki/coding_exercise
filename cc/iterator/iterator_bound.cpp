#include <iostream>
#include <iterator>
#include <vector>
#include <map>
 
int main() 
{
    std::map<unsigned int, std::string> m;
    m.insert(std::pair<unsigned int, std::string>(0, "test0"));
    m.insert(std::pair<unsigned int, std::string>(1, "test1"));
    m.insert(std::pair<unsigned int, std::string>(2, "test2"));
    m.insert(std::pair<unsigned int, std::string>(3, "test3"));
    m.insert(std::pair<unsigned int, std::string>(4, "test4"));
    auto itr = m.lower_bound(4.2);
    std::cout << "Test:lower_bound " << itr->second << std::endl;
    if (itr == m.end()) {
        std::cout << "lol" << std::endl;
    }
    auto itr2 = m.upper_bound(4.2);
    std::cout << "Test:upper_bound " << itr2->second << std::endl;
    return 0;
}
