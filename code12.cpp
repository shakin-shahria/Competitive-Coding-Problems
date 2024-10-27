// WAP that will determine whether a number is prime or not.

// Sample input    --->       sample output
// 1               --->           Not prime
// 2               --->           Prime
// 11              --->           Prime
// 39              --->           Not prime
// 101             --->          Prime


#include <iostream>
using namespace std;

int main() {
    int n, i;

    // Input the number
    cout << "Enter a number: ";
    cin >> n;

    // Check if the number is less than 2 (1 is not prime, 0 is not prime)
    if (n < 2) {
        cout << n << " is Not Prime" << endl;
        return 0;
    }

    // Check for divisors from 2 up to n/2
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) { // if n is divisible by any i, it's not prime
            cout << n << " is Not Prime" << endl;
            return 0;
        }
    }

    // If no divisors are found, it's prime
    cout << n << " is Prime" << endl;
    return 0;
}

