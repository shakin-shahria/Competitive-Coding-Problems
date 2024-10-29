// WAP that will print a pattern based on the input integer n. Please see the sample input output.
// Sample input   ---->   Sample output
// 3              ---->     __1 
//                          _22 
//                          333
//
// 5             ---->    ____1 
//                        ___22 
//                        __333 
//                        _4444 
//                        55555      
#include<iostream>
using namespace std;
int main(){
 int i,n,j;
 cout<<"Enter the value of n: ";
 cin >> n;

  // Outer loop for rows
    for (int i = 1; i <= n; i++) {
        // Inner loop for spaces
        for (int j = 1; j <= n - i; j++) {
            cout << "_";
        }
        // Inner loop for numbers
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        // Move to the next line after each row
        cout << endl;
    }

 return 0;
}
