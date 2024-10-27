/*Write a program (WAP) that will take two numbers X and Y as inputs. 
Then it will print the square of X and increment (if X<Y) or decrement (if X>Y) X by 1, until X reaches Y. 
If and when X is equal to Y, the program prints “Reached!”*/ 


// Sample input(X,Y)     --->          Sample output
//   10       5          --->           100, 81, 64, 49, 36, Reached!
//   5        10         --->           25, 36, 49, 64, 81, Reached!
//  10       10          --->           Reached!
 
 #include <iostream>
using namespace std;

int main() {
    int X, Y;

   
    cout << "Enter value for X: ";
    cin >> X;
    cout << "Enter value for Y: ";
    cin >> Y;

    
    while (X != Y) {
        
        cout << (X * X) << ", ";

        
        if (X < Y) {
            X++; // Increment if X < Y
        } else {
            X--; // Decrement if X > Y
        }
    }

    // Once X is equal to Y
    cout << "Reached!" << endl;

    return 0;
}
