#include "gtest/gtest.h"
#include "myint.h"

class MyIntTest : public ::testing::Test {
    protected:
        int addTwoInts(int a, int b) {my_int.addTwoInts(a, b);}
    private:
        MyInt my_int;
};

TEST_F(MyIntTest, isOdd) {
    MyInt mi1 = MyInt(10);
    EXPECT_EQ(false, mi1.isOdd());

    MyInt mi2 = MyInt(13);
    EXPECT_EQ(true, mi2.isOdd());
}

TEST_F(MyIntTest, isEven) {
    MyInt mi1 = MyInt(10);
    EXPECT_EQ(true, mi1.isEven());

    MyInt mi2 = MyInt(13);
    EXPECT_EQ(false, mi2.isEven());
}

TEST_F(MyIntTest, addTwoIntsTest) {
    int a = 1;
    int b = 2;
    EXPECT_EQ(addTwoInts(a, b), 3);
}