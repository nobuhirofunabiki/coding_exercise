#! /usr/bin/env python3

from class_1 import Class1

class Class2():

    def __init__(self, arg):
        self.variable = arg

    def print_class1_class_variable(self):
        class1 = Class1(0,1)
        print('In Class2')
        class1.print_class_variable()