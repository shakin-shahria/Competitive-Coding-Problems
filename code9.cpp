// Write a program (WAP) that will print the factorial (N!) of a given number N. Please see the sample input output.
// Sample input   ---->           Sample output
//    1           ---->             1! = 1 = 1 
//    2           ---->             2! = 2 X 1 = 2
//    3           ---->             3! = 3 X 2 X 1 = 6
//    
#include <iostream>
using namespace std;

int main() {
    int n, factorial = 1;

    cout << "Enter the value of n: ";
    cin >> n;

    // Print the factorial expression
    cout << n << "! = ";
    
    // Loop to calculate factorial
    for (int i = 1; i <= n; i++) {
        //factorial *= i;
        factorial = factorial* i;
        cout << i; // Print the current term
        
        if (i < n) {
            cout << " X "; // Print 'X' between terms
        }
    }

    // Print the result
    cout << " = " << factorial << endl;

    return 0;
}
