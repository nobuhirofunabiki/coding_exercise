#! /usr/bin/env python3

class Class1():
    class_variable = 1
    def __init__(self, arg1, arg2):
        self.variable1 = arg1
        self.variable2 = arg2
    
    @classmethod 
    def set_class_variable(self, arg):
        self.class_variable = arg
    
    # def set_class_variable(self, arg):
    #     self.class_variable = arg
    
    def print_class_variable(self):
        print('Class variable of Class1 is %d', self.class_variable)
        print('')