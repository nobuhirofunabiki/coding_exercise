// Sample cord of weak_ptr
// Ref: https://qiita.com/hmito/items/db3b14917120b285112f

#include <iostream>
#include <memory>

class SampleClass {
    public:
        SampleClass(){}
        ~SampleClass(){}
        void testOperators() const;
    private:
};


void SampleClass::testOperators() const {
    std::shared_ptr<std::string> s_ptr = std::make_shared<std::string>("test");
    std::weak_ptr<std::string> w_ptr(s_ptr);

    // * and -> operators cannot be used for weak_ptr
    // std::cout << "Value which is pointed to by w_ptr : " << *w_ptr << "\n";
    // std::cout << "Size of the value which is pointed to by w_ptr : " << w_ptr->size() << "\n";

    std::shared_ptr<std::string> l_ptr = w_ptr.lock();
    std::cout << "Value which is pointed to by l_ptr : " << *l_ptr << "\n";
    std::cout << "Size of the value which is pointed to by l_ptr : " << l_ptr->size() << "\n";
}


int main() {
    SampleClass class_instance_;
    class_instance_.testOperators();

    return 0;
}

