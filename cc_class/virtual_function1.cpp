// Sample program to illustrate how virtual functions work
// Late binding (Runtime) is done in accordance with the
// content of pointer and Early binding (Complie time) is done
// accordance with the type of pointer
// (ref) https://www.geeksforgeeks.org/virtual-function-cpp/

#include <iostream>

class BaseClass {
    public:
        virtual void print() {
            std::cout << "Print base class" << std::endl;
        }

        void show() {
            std::cout << "Show base class" << std::endl;
        }
};

class DerivedClass : public BaseClass {
    public:
        void print() {
            std::cout << "Print derived class" << std::endl;
        }

        void show() {
            std::cout << "Show derived class" << std::endl;
        }
};

int main() {
    BaseClass *base_ptr;
    DerivedClass derived;
    base_ptr = &derived;

    // Virtual function, binded at runtime
    base_ptr->print();

    // Non-virtual function, binded at compile time
    base_ptr->show();
}