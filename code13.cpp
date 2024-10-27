// Write a program (WAP) that will reverse the digits of an input integer.

// Sample input            Sample output
// 13579         --->            97531
// 
// 1234          --->            4321

#include <iostream>
using namespace std;

int main() {
    int n, reversed = 0;

    
    cout << "Enter a number: ";
    cin >> n;

    // Reverse the digits
    while (n != 0) {
        reversed = reversed * 10 + (n % 10); // Append the last digit of n to reversed
        n /= 10; // Remove the last digit from n
    }

  
    cout << "Reversed: " << reversed << endl;

    return 0;
}
