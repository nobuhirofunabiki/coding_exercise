// Sample cord of unique_ptr
// Ref: https://qiita.com/hmito/items/db3b14917120b285112f

#include <iostream>
#include <memory>

class SampleClass {
    private:
        std::unique_ptr<int> ptr_;
    public:
        SampleClass(int value):ptr_(new int(value)) {}
        int getValue() const {return *ptr_;}
        void testMakeUniquePtr() const;
        void testReleaseUniquePtr() const;
        void testReturnOwnership() const;
        void testGetFunction() const;
        void testReleaseFunction();
};

void SampleClass::testMakeUniquePtr() const {
    // It is possible to give an address allocated dynamically as 
    // an argument of the constructor
    std::unique_ptr<int> ptr(new int(10));

    // Initialization be reset function
    std::unique_ptr<int> ptr2;
    ptr2.reset(new int(10));

    // Initialization by make_unique function (after C+14)
    std::unique_ptr<int> ptr3 = std::make_unique<int>(10);

    // Release -------------------------------------------------------
    // The memories allocated by unique_ptr are automatically released
    // by the destructor of unique_ptr
}

void SampleClass::testReleaseUniquePtr() const {
    // Make a new unique_ptr
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    // It's possible to release the pointer explicitly as follows
    ptr.reset();
}

void SampleClass::testReturnOwnership() const {
    if (ptr_) {
        std::cout << "It has the ownership of ptr" << "\n";
    }
    else {
        std::cout << "It does not have the ownership of ptr" << "\n";
    }
}

void SampleClass::testGetFunction() const {
    // get() just returns a raw pointer, ptr_ still keeps the ownership
    int* ptr;
    ptr = ptr_.get();
    std::cout << "testGetFunction" << "\n";
    std::cout << *ptr << "\n";
}

void SampleClass::testReleaseFunction() {
    // release() give the ownership to others (in this case, ptr)
    // Therefore, the memory release needs to be done by delete operator
    int* ptr;
    ptr = ptr_.release();
    std::cout << "testReleaseFunction" << "\n";
    std::cout << *ptr << "\n";
    delete ptr;
}

int main() {
    SampleClass sample_class_1(10);

    // This cannot be compiled because ptr, which is defined as unique pointer, cannot be copied.
    // SampleClass sample_class_2(sample_class_1);

    // It is possible to move the ownership
    SampleClass sample_class_2(std::move(sample_class_1));
    sample_class_1.testReturnOwnership();
    sample_class_2.testReturnOwnership();

    sample_class_1.testMakeUniquePtr();
    sample_class_1.testReleaseUniquePtr();
    
    // sample_class_1.testGetFunction();
    sample_class_2.testGetFunction();

    // sample_class_1.testReleaseFunction();
    sample_class_2.testReleaseFunction();

    return 0;
}
