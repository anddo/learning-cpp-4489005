// Learning C++ 
// Exercise 03_06
// Pointers, by Eduardo Corpeño 

#include <iostream>
#include <string>

int main(){

int a = 45;
int* ptr;
ptr = &a;


    std::cout << "a: " << a << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "&a: " << &a << std::endl;
    std::cout << "*ptr: " << *ptr << std::endl;
    std::cout << "&ptr: " << &ptr << std::endl;
    return (0);
}
