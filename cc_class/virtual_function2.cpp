// Sample program to illustrate how virtual functions work
// (ref) https://www.geeksforgeeks.org/virtual-function-cpp/

#include <iostream>

class BaseClass {
    public:
        void function1() {std::cout << "base-1\n";}
        virtual void function2() {std::cout << "base-2\n";}
        virtual void function3() {std::cout << "base-3\n";}
        virtual void function4() {std::cout << "base-4\n";}
};

class DerivedClass : public BaseClass {
    public:
        void function1() {std::cout << "derived-1\n";}
        void function2() {std::cout << "derived-2\n";}
        void function4(int x) {std::cout << "derived-3\n";}
};

int main() {
    BaseClass *base_ptr;
    DerivedClass derived;
    base_ptr = &derived;

    // Non-virtual function, binded at complie time (early binding)
    base_ptr->function1();

    // Virtual function, binded at run time (late binding)
    base_ptr->function2();

    // Binded at run time (late binding)
    base_ptr->function3();

    // Binded at run time (late binding)
    base_ptr->function4();

    // This is not allowed.
    // base_ptr->function4(5);
}