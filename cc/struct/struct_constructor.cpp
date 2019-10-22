// A sample cord for C++ struct constructors
// (ref) http://www.c-jump.com/bcc/c123d/Lectures/wk08_struct/W08_0050_c_struct_constructo.htm


#include <iostream>

struct Rectangle {
    int width;
    int height;

    Rectangle() {
        width = 0;
        height = 0;
    }

    Rectangle(int width_, int height_) {
        width = width_;
        height = height_;
    }
};

void showRectangle(Rectangle rec) {
    std::cout << "width: " << rec.width << "\n";
    std::cout << "height: " << rec.height << "\n";
}

int main() {
    Rectangle rectangle_;
    showRectangle(rectangle_);

    rectangle_ = Rectangle(1,2);
    showRectangle(rectangle_);

    return 0;
}