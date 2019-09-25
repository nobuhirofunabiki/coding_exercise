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
    auto it2 = m.begin();
    auto it3 = std::next(it2, 1);
    std::cout << "No." << it2->first << " : " << it2->second << std::endl;
    std::cout << "No." << it3->first << " : " << it3->second << std::endl;
}