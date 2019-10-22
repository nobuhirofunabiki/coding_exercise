// Sample cord to illustrate how to use reference
// (ref) https://www.geeksforgeeks.org/references-in-c/
// Avoid copy of large structure

#include <iostream>

struct Student {
    std::string name;
    std::string address;
    int number;
};

void print(const Student &s) {
    std::cout << "name:\t\t " << s.name << "\n";
    std::cout << "address:\t " << s.address << "\n";
    std::cout << "number:\t\t " << s.number << "\n";
}

int main() {
    Student student1;
    student1.name = "Nobuhiro";
    student1.address = "Nihon";
    student1.number = 1;
    print(student1);
    return 0;
}