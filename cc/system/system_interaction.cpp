#include <iostream>
#include <bits/stdc++.h>

int main() {
    std::string command_str = "ls";
    const auto command = command_str.c_str();
    system(command);

    return 0;
}