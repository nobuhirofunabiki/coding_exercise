#include <iostream>

const unsigned int SWITCH_TEST_ZERO = 0;
const unsigned int SWITCH_TEST_ONE = 1;
const unsigned int SWITCH_TEST_TWO = 2;

int main() {
    auto switch_test = SWITCH_TEST_ZERO;
    switch(switch_test) {
        case SWITCH_TEST_ZERO:
            std::cout << "zero" << std::endl;
            break;
        case SWITCH_TEST_ONE:
            std::cout << "one" << std::endl;
            break;
        case SWITCH_TEST_TWO:
            std::cout << "two" << std::endl;
            break;
        default:
            std::cout << "Invalid argument";
            break;
    }
    return 0;
}