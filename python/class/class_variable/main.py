#! /usr/bin/env python3

from class_1 import Class1
from class_2 import Class2

if __name__ == '__main__':
    class1_A = Class1(0, 1)
    # class1_A.set_class_variable(2)
    Class1.class_variable = 2
    class1_A.print_class_variable()

    class2_A = Class2(3)
    class2_A.print_class1_class_variable()

    # class1_A.set_class_variable(2)
    class1_A.print_class_variable()

    class2_A.print_class1_class_variable()

    # class2_B = Class2(3)
    # class2_B.print_class1_class_variable()

    # class1_B = Class1(0, 1)
