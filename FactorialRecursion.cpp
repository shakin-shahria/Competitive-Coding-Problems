#include<iostream>
using namespace std;


int fact(int n){
   
   if(n==1){
    return 1;
   }
   else
   {
    int restoffact =fact(n-1);
    return restoffact*n;
   }



}

int main(){


    int n= 10;

    cout<<n<<" Factorial is: "<<fact(n);

}