// Program that will take two numbers X & Y as inputs and decide whether X is greater than/less 
// than/equal to Y.
// Sample input (X,Y)
// Sample output
// 5      -10
// 5 is greater than -10
// 5       10
// 5 is less than 10
// 5       5
// 5 is equal to 5

#include <iostream>
using namespace std;
int main(){
    
    int number1, number2;

    cout<<"Enter your First number: ";
    cin>> number1;


    cout<<"Enter your Second number: ";
    cin>> number2;

    if(number1>number2){
        cout<<number1<<" is greated than "<<number2;
    }

    else if(number1<number2){
        cout<<number1<<" is lesser than "<<number2;
    }

    else{
        
        cout<<number1<<" and "<<number2<<" are equal";

    }
}