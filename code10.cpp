// Write a program (WAP) that will print following series upto N   terms.
// 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, …….
// 
// Sample input      ---->            Sample output
// 2                 ---->              1, 0
// 3                 ---->              1, 0, 1
// 4                 ---->              1, 0, 1, 0


#include <iostream>
using namespace std;
int main(){

 int n,i;

 cout<<"Enter the value of n: ";
 cin>> n;

 for (i=1;i<=n;i++){

   if (i%2==0){
    cout<<0<<" ";
   }
   
   else{

    cout<<1<<" ";
   }



 }





}