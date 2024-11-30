// WAP that will print a pattern based on the input integer n. Please see the sample input output.
// Sample input ----> Sample output
// 4            ---->   ****
//                      ****
//                      ****
//                      ****
// 
// 2           ---->    **
//                      **
#include<iostream>
using namespace std;
int main(){
 int i,n,j;
 cout<<"Enter the value of n: ";
 cin >> n;

 for(i=1;i<=n;i++){

     for(j=1;j<=n;j++){   // Inner loop for columns
       
       cout<<"*";
     }
    
    cout<<endl;

 }

 return 0;
}