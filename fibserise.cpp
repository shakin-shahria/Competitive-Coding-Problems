//0, 1, 1, 2, 3, 5, 8...
#include<iostream>
using namespace std;

int serise(int n){

   if(n==0){
    return 0;
   }
   else if(n==1){
    return 1;
   }
   else{
             
      return serise(n-1)+serise(n-2);

   }

}

int main(){


    int n =6;
    cout<<serise(n);
}