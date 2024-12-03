#include<iostream>
using namespace std;

int sumofOdd(int arr[],int low,int high){
    int sum =0;
     if(low==high){
        if(arr[low]%2==0){
            return sum;
        }
        else{
            return sum+arr[low];
        }
     }
      int mid=(low+high)/2;
     int left = sumofOdd(arr,low,mid);
     int right = sumofOdd(arr,mid+1,high);
     return left+right;


}

int main(){
    int n=3;
    int arr[n]={1,2,3};
    cout<<sumofOdd(arr,0,n-1);
}