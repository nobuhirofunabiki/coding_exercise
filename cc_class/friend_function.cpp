// Sample cord to illustrate how a friend function works
// (ref) https://www.geeksforgeeks.org/friend-class-function-cpp/

#include <iostream>

class Ben;

class John {
    public:
        void showBen(Ben&);
};

class Ben {
    private:
        int b;

    public:
        Ben() {b = 1;}
        friend void John::showBen(Ben& x);
};

void John::showBen(Ben& x) {
    std::cout << "Ben::b = " << x.b << std::endl;
}

int main() {
    John john;
    Ben ben;
    john.showBen(ben);
    return 0;
}