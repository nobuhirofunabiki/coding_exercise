#include <iostream>

class MyInt {

    // For testing the private functions in gtest
    friend class MyIntTest;

    public:
        MyInt();
        MyInt(int num);
        ~MyInt();
        bool isOdd();
        bool isEven();
    
    private:
        int num_;
        int addTwoInts(int a, int b);
        double addTwoDoubles(double a, double b);
        
        template <typename TYPE>
        TYPE addTwoValues(TYPE a, TYPE b);
};