#include <iostream>
#include <iterator>
#include <vector>
#include <map>
 
int main() 
{
    std::vector<int> v{ 3, 1, 4 };
    auto it = v.begin();
    auto nx = std::next(it, 2);
    std::cout << *it << ' ' << *nx << '\n';

    std::map<unsigned int, std::string> m;
    m.insert(std::pair<unsigned int, std::string>(0, "test0"));
    m.insert(std::pair<unsigned int, std::string>(1, "test1"));
    m.insert(std::pair<unsigned int, std::string>(2, "test2"));
    m.insert(std::pair<unsigned int, std::string>(3, "test3"));
    m.insert(std::pair<unsigned int, std::string>(4, "test4"));
    m.insert(std::pair<unsigned int, std::string>(5, "test5"));

    std::cout << "Test-1:-----------------------------" <<std::endl;
    auto it2 = m.begin();
    auto it3 = std::next(it2, 1);
    std::cout << "No." << it2->first << " : " << it2->second << std::endl;
    std::cout << "No." << it3->first << " : " << it3->second << std::endl;
    auto it4 = m.rbegin();
    auto it5 = std::next(m.rbegin(), 4);
    std::cout << "No." << it4->first << " : " << it4->second << std::endl;
    std::cout << "No." << it5->first << " : " << it5->second << "\n\n";

    std::cout << "Test-2:-----------------------------" <<std::endl;
    auto l = m;
    auto it_l = std::next(l.rbegin(), 4);
    l.erase(l.begin(), it_l.base());
    for (const auto& [first, second] : l) {
        std::cout << "No." << first << " : " << second << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Test-3:-----------------------------" <<std::endl;
    auto n = m;
    auto it_begin = n.begin();
    auto it_last = std::next(it_begin, 3);
    std::cout << "No." << it_last->first << " : " << it_last->second << "\n\n";
    n.erase(it_begin, it_last);
    for (const auto& [first, second] : n) {
        std::cout << "No." << first << " : " << second << std::endl;
    }
    std::cout << std::endl; 

    return 0;
}