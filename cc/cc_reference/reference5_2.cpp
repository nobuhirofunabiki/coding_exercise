// Sample cord to illustrate how to use reference in c++
// (ref) http://wisdom.sakura.ne.jp/programming/cpp/cpp13.html

#include <iostream>

class Base {
    private:
        int X;
    public:
        int& getX();
};

// int& Base::getX() {
int &Base::getX() {
    return X;
}

int main() {
    Base obj;
    obj.getX() = 10;
    std::cout << obj.getX() << std::endl;
    return 0;
}