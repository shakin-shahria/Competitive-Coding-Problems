/*Write a program (WAP) for the described scenario: 
Player-1 picks a number X and Player-2 has to guess that number within N tries. For each wrong guess by Player-2, 
the program prints “Wrong, N-1 Choice(s) Left!” If Player-2 at any time successfully guesses the number, 
the program prints “Right, Player-2 wins!” and terminates right away.
 Otherwise after the completion of N wrong tries, the program prints “Player-1 wins!” and halts.*/


//  Sample input              --->                       Sample output
// (X,N,n1, n2,..,nN)           
// 5                          --->                            Wrong, 2 Choice(s) Left!  
// 3                          --->                            Wrong, 1 Choice(s) Left!
// 12   8   5                 --->                            Right, Player-2 wins!


// 20                         --->                            Wrong, 2 Choice(s) Left! 
// 3                           --->                           Wrong, 1 Choice(s) Left! 
// 12  8  5                    --->                           Wrong, 0 Choice(s) Left!
//                                                            Player-1 wins!



#include<iostream>
using namespace std;

int main() {
    int X, guess, N;

    
    cout << "Player-1, enter your number: ";
    cin >> X;

    
    cout << "Set the number of guesses: ";
    cin >> N;

    
    for (int i = 1; i <= N; i++) {
        
        cout << "Player-2, enter your guess: ";
        cin >> guess;

        
        if (guess == X) {
            cout << "Right, Player-2 wins!" << endl;
            return 0;  
        }
        
        else {
            cout << "Wrong, " << (N - i) << " Choice(s) Left!" << endl;
        }
    }

    cout << "Player-1 wins!" << endl;

    return 0;
}
