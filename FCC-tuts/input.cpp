#include <iostream>
#include <string>

int main (){
    std::string name;
    int age;

    //Getting data
    /* std::cout << "enter you name: ";
    std::cin >> name;
    std::cout << "enter you age: ";
    std::cin >> age;

    std::cout << "Your name: " << name << std::endl;
    std::cout << "Your age: " << age << std::endl; */


    //Data via one line
    /* std::cin >> name >> age;

    std::cout << "Your name: " << name << std::endl;
    std::cout << "Your age: " << age << std::endl; */
    
    //Data with spaces

    // std::string full_name;
    
    // std::cout << "Enter your name: ";
    // std::getline(std::cin, full_name);

    // std::cout << "Enter your age: ";
    // std::cin >> age;

    // std::cout << "Your name: " << full_name << " Your age: " << age << std::endl;


    // int age;
    // std::cin >> age;


    std::string full_name;
    std::getline(std::cin, full_name);

}