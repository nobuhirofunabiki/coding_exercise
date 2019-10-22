// Cndop1.cpp
#include <iostream>

int main()
{
    int num1, num2;

    std::cout << "２つ値を入力してください >";
    std::cin >> num1 >> num2;
    std::cout << "大きいほうの値は"
    << ((num1 > num2) ? num1 : num2) << "です。" << std::endl;

    return 0;
}