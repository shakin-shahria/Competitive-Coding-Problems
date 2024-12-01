#include<iostream>
using namespace std;

struct CountEvenOddinArray
{
    int even_counter;
    int odd_counter;
};

CountEvenOddinArray evenoddCounter(int arr[],int n){
   
   if(n==1){
   // int x = arr[0];
    if(arr[0]%2 ==0){
        return {1,0};
    }
    else{
        return {0,1};
    }
   }
   else{
      int lastElement = arr[n-1];
      CountEvenOddinArray result = evenoddCounter(arr,n-1);
      if(lastElement%2==0){
        return {result.even_counter+1,result.odd_counter};
      }
      else{
        return{result.even_counter,result.odd_counter+1};
      }
   }


}


int main(){
    int n =4;
    int arr[n]={1,2,3,4};
    CountEvenOddinArray answer = evenoddCounter(arr,n);
    cout<<"Even: "<<answer.even_counter<<endl;
    cout<<"Odd: "<<answer.odd_counter<<endl;
}