#include <iostream>
 
template<typename TYPE, std::size_t SIZE>
std::size_t array_length(const TYPE (&)[SIZE]) {return SIZE;}
 
int main()
{   
    int array1[10];
    int array2[20];
    int array3[30];
 
    std::cout << array_length(array1) << std::endl;
    std::cout << array_length(array2) << std::endl;
    std::cout << array_length(array3) << std::endl;
}