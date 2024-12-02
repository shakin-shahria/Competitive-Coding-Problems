#include<iostream>
using namespace std;

int sumofArray(int arr[],int low,int high){

    if(low==high){
        return arr[low];
    }
    else{
        int mid =(low+high)/2;
        int left = sumofArray(arr,low,mid);
        int right = sumofArray(arr,mid+1,high);
        int sum;
        sum = left+right;
        return sum;
    }




}


int main(){
    int n =5;
    int arr[n]= {1,2,3,4,5};
    int answer = sumofArray(arr,0,n-1);
    cout<<"Sum of the Array: "<< answer;
}