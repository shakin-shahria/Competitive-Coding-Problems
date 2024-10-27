// WAP that will determine whether an integer is palindrome number or not.
// Sample input    ---->    Sample output
// 9               ---->            Yes
// 91              ---->            No
// 222             ---->            Yes
// 12321           ---->            Yes
// 110             ---->            No
// 


#include <iostream>
using namespace std;

int main() {
    int n, original, reversed = 0;

    // Input the number
    cout << "Enter a number: ";
    cin >> n;

    original = n; 

    // Reverse the number
    while (n != 0) {
        reversed = reversed * 10 + (n % 10); // Append the last digit to reversed
        n /= 10; // Remove the last digit from n
    }

    // Checking
    if (original == reversed) {
        cout << "Yes" << endl; // Palindrome
    } else {
        cout << "No" << endl; // Not a palindrome
    }

    return 0;
}