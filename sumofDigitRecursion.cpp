#include<iostream>
using namespace std;



int sumofDigits(int n){
    if(n>=0 && n<=9){
        return n;
    }

    else{

        int lastDigit = n%10;
        int sumofRestDigits = sumofDigits(n/10);
        int sum = sumofRestDigits+lastDigit;
        return sum;
    }
}

int main(){

   int n;
   cout<<"Please enter your number: "<< endl;
   cin>> n;
   int result = sumofDigits(n);
   cout<<"The Sum: "<<result<<endl;

}