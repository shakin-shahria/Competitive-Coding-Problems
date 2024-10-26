// Write a program (WAP) that will print following series upto Nth terms.
// 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31 …



#include<iostream>
using namespace std;
int main(){

 int n,i;
 cout<<"Enter the valur of n: "<<endl;
 cin>> n;
 for (i=0;i<n;i++){

  cout<<2*i+1<<" ";

 }
 
 cout<<endl;

}