#include <stdio.h>

int main() {
    char name[50];
    int age;

    // Asking for user input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);  // Read a string with spaces
    printf("Enter your age: ");
    scanf("%d", &age);  // Read an integer

    // Display the output
    printf("\nHello, %sYou are %d years old.\n", name, age);

    return 0;
}
