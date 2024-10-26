// Program that will construct a menu for performing arithmetic operations. The user will give two real numbers (a, b) on which the arithmetic operations will be performed and an integer number (1 <= Choice <= 4) as a choice. 
// Choice-
// 1 for performing addition
// 2 for performing subtraction
// 3 for performing multiplication
//  4 for performing  division.

#include <iostream>
using namespace std;
int main(){

 int n1,n2,choice,result;

 cout<<"Enter Your first number: ";
 cin>> n1;

 cout<<"Enter Your second number: ";
 cin>> n2;

 cout<<"Enter Yours choice: "<<endl;
 cout<< "1.Addition"<<endl;
 cout<< "2.Subtraction"<<endl;
 cout<< "3.Multiplication"<<endl;
 cout<< "4.Division"<<endl;
 cin>> choice;

 if (choice ==1){

    result = n1+n2;
    cout<<n1<<" + "<<n2<<" is "<<result<<endl;

 }

else if (choice ==2){

    result = n1-n2;
    cout<<n1<<" - "<<n2<<" is "<<result<<endl;

 }

 else if (choice ==3){

    result = n1*n2;
    cout<<n1<<" * "<<n2<<" is "<<result<<endl;

 }

 else if (choice ==4){

    result = n1/n2;
    cout<<n1<<" / "<<n2<<" is "<<result<<endl;

 }

 else{
    cout<<"Wrong input"<<endl;
 }
 








}