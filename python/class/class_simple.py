class SimpleExample():

    def __init__(self, a, b):
        self.num1 = a
        self.num2 = b
    
    def print_sum(self):
        sum = self.num1 + self.num2
        print(sum)

instance = SimpleExample(1,2)
instance.print_sum()