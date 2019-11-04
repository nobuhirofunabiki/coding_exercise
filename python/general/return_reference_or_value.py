class Human:

    def __init__(self, name):
        self.name = name
    
    def get_name(self);
        return self.name
    
    def set_name(self, name):
        self.name = name

def main():
    print("Application starts")
    h = Human("Matteo")
    print(h.get_name())
    local_name = h.get_name()
    print("Local name is " + local_name)
    h.set_name("Nobuhiro")
    print("Class name is " + h.get_name())
    print("Local name is " + local_name)

if __name__ == "__main__":
    main()