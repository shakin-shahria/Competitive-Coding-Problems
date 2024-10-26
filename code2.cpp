#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;

    // Asking for user input
    std::cout << "Enter your name friend: ";
    std::getline(std::cin, name);  // Read a string with spaces
    std::cout << "Enter your age: ";
    std::cin >> age;  // Read an integer

    // Display the output
    std::cout << "\nHello, " << name << ". You are " << age << " years old." << std::endl;

    return 0;
}
