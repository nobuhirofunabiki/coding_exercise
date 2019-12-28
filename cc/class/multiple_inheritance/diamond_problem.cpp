// references
// https://www.geeksforgeeks.org/multiple-inheritance-in-c/
// http://www.ced.is.utsunomiya-u.ac.jp/lecture/2012/prog/p3/kadai3/multipleinheritance2.php

#include <iostream>

class Person {
    public:
        Person() {
            std::cout << "Person::Person()" << std::endl;
        }
        Person(double height) {
            height_ = height;
            std::cout << "Person::Person(double height)" << std::endl;
        }
    private:
        double height_;
};

class Faculty : virtual public Person {
// class Faculty : public Person {
    public:
        Faculty(double height):Person(height) {
            std::cout << "Faculty::Faculty(double height)" << std::endl;
        }
};

class Student : virtual public Person {
// class Student : public Person {
    public:
        Student(double height):Person(height) {
            std::cout << "Student::Student(double height)" << std::endl;
        }
};

class TA : public Faculty, public Student {
    public:
        // TA(double height):Student(height), Faculty(height) {
        TA(double height):Student(height), Faculty(height), Person(height) {
            std::cout << "TA::TA(double height)" << std::endl;
        }
};

int main() {
    TA Jack(165.0);
}