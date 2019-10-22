// Sample cord to illustrate how a friend class works
// (ref) https://www.geeksforgeeks.org/friend-class-function-cpp/

#include <iostream>

class John {
    private:
        int a;

    public:
        John() {a = 1;}
        friend class Ben;
};

class Ben {
    private:
        int b;
    
    public:
        void showJohn(John& x) {
            std::cout << "John::a = " << x.a << std::endl;
        }
};

int main() {
    John john;
    Ben ben;
    ben.showJohn(john);
    return 0;
}