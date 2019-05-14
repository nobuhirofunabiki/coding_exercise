// Temp3.cpp
#include <iostream>

template <typename TYPE>
TYPE Max(TYPE a, TYPE b)
{
    return (a > b) ? a : b;
}

int main()
{
    void* p;
    char  str[100];
    int   num;

    p = Max<void*>(str, &num);
    std::cout << "より大きいアドレスは "
    << p << "です。" << std::endl;

    return 0;
}