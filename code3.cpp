// WAP Program that will decide whether a number is even or odd..
#include <iostream>
using namespace std;
int main(){
   
    int number;
    cout<<"Please Enter the number: ";
    cin>> number;
    if(number%2 == 0){
        cout<<number<<" is an even number";
    }
    else{
        cout <<number<<" is an odd number";
    }
}