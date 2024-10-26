// Write a code in C++ to check whether the input is an alphabet, a digit or a special character.
// Sample input 
// Sample output
// z
// Alphabet 
// A
// Alphabet
// 8
// Digit
// *
// Special

#include <iostream>
using namespace std;
int main(){
    
    char input;

    cout<<"Enter your input: ";
    cin>> input;

    if ((input>='a' && input<='z')||(input>='A'&& input<='Z')){

        cout<<input<<" is a Character."<< endl;
    }

    else if (input>='0' && input<='9'){

        cout<<input<<" is a Digit."<< endl;
    }
    else{
        cout<<input<<" is a Special Character."<< endl;
    }


}

