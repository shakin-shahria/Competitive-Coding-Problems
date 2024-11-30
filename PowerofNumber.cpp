#include<iostream>
using namespace std;


int cal_pow(int x,int n){

  if (n==0){
      
      return 1;
  }

  else{
    int rest = cal_pow(x,n-1);
    return x*rest;
    
  }

}

int main(){


    int x,n;
    cout<<"Enter the valur of X: "<<endl;
    cin>>x;

    cout<<"Enter the valur of N: "<<endl;
    cin>>n;

    int result=cal_pow(x,n);
    cout<<x<<"^"<<n<<"="<<result;

}