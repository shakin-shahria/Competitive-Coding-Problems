// WAP that will print a pattern based on the input integer n. Please see the sample input output.

// Sample input    --->    Sample output
// 3                        123
//                          234
//                          345
// 
//4               --->   1234
//                       2345
//                       3456
//                      4567 
// 
 

#include<iostream>
using namespace std;
int main(){
 int i,n,j;
 cout<<"Enter the value of n: ";
 cin >> n;

 for(i=1;i<=n;i++){

     for(j=i;j<i+n;j++){   // Inner loop for columns
       
       cout<<j;
     }
    
    cout<<endl;

 }

 return 0;
}