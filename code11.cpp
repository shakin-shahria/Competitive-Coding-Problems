// Write a program (WAP) that will print Fibonacci series upto N   terms.
// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, …….
// 
// Sample input        ---->              Sample output
// 1                   ---->                   1
// 2                   ---->                   1, 1
// 4                   ---->                   1, 1, 2, 3
// 7                   ---->                   1, 1, 2, 3, 5, 8, 13


#include <iostream>
using namespace std;

int main() {
    int n, first = 1, second = 1, next;

    // Input the number of terms
    cout << "Enter the number of terms: ";
    cin >> n;

    // Special case for when no terms are required
    if (n == 0) {
        return 0;
    }

    // Print the first term
    cout << first;

    // Handle printing for terms beyond the first one
    for (int i = 2; i <= n; i++) {
        if (i == 2) {
            
            cout << ", " << second;
        } else {
            // Calculate the next term
            next = first + second;
            cout << ", " << next;
            
            // Shifting values for the next iteration
            first = second;
            second = next;
        }
    }

    cout << endl;  
    return 0;
}







