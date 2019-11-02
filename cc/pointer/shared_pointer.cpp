// Sample cord of shared_ptr
// Ref: https://qiita.com/hmito/items/db3b14917120b285112f

#include <iostream>
#include <memory>

class SampleClass {
    public:
        SampleClass(const int value);
        void testSimpleCase() const;
        void checkOwnership() const;
        void testAccessValue() const;
        void getRawPointer() const;
    private:
        std::shared_ptr<int> ptr_;
};

SampleClass::SampleClass(const int value)
: ptr_(new int(value)) {}

void SampleClass::testSimpleCase() const {
    std::shared_ptr<int> ptr;
    {
        std::shared_ptr<int> ptr2(new int(0));
        ptr = ptr2;
        *ptr += 10;
        *ptr2 += 10;
    } // The destructor of ptr2 is called here.
    // ptr still has the ownership of the memory, 
    // so it's not released at this moment.
    std::cout << "ptr=" << *ptr << "\n";
}// The destructor of ptr is called here.
// No pointer has the ownership of the memory,
// so it is released here.

void SampleClass::checkOwnership() const {
    // Empty shared_ptr
    std::shared_ptr<int> ptr;
    if (ptr) std::cout << "It has the ownership of ptr" << "\n";
    else std::cout << "It does not have the ownership of ptr" << "\n";
    std::cout << "use_count of ptr = " << ptr.use_count() << "\n";
    // Shared_ptr initialized by make_shared
    std::shared_ptr<int> ptr2 = std::make_shared<int>(20);
    if (ptr2) std::cout << "It has the ownership of ptr2" << "\n";
    else std::cout << "It does not have the ownership of ptr" << "\n";
    std::cout << "use_count of ptr2 = " << ptr2.use_count() << "\n";
    // Shared_ptr in the private variable of the class
    if (ptr_) std::cout << "It has the ownership of ptr_" << "\n";
    else std::cout << "It does not have the ownership of ptr_" << "\n";
    std::cout << "use_count of ptr_ = " << ptr_.use_count() << "\n";
}

void SampleClass::testAccessValue() const {
    std::shared_ptr<std::string> str_ptr
        = std::make_shared<std::string>("test");
    // It is possible to access to the value by * operator
    std::cout << *str_ptr << "\n";
    // It is possible to access directly to the value by -> operator
    auto str_size = str_ptr->size();
    std::cout << "The size of value which str_ptr points to : " << str_size << "\n";
}

void SampleClass::getRawPointer() const {
    std::shared_ptr<int> ptr = std::make_shared<int>(10);
    int* raw_ptr;
    raw_ptr = ptr.get();
    std::cout << "Raw pointer (raw_ptr) : " << raw_ptr << "\n";
    std::cout << "Value (*raw_ptr) : " << *raw_ptr << "\n";
}

int main() {
    SampleClass class_instance_(10);
    class_instance_.testSimpleCase();
    class_instance_.checkOwnership();
    class_instance_.testAccessValue();
    class_instance_.getRawPointer();
    return 0;
} 