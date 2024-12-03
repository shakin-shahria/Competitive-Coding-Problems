#include<iostream>
using namespace std;

int productofArray(int arr[],int low,int high){

    if(low==high){
        return arr[low];
    }
    else{
        int mid=(low+high)/2;
        int left= productofArray(arr,low,mid);
        int right=productofArray(arr,mid+1,high);
        return left*right;
    }

}

int main(){
    int n= 3;
    int arr[n]={3,3,3};
    cout<<productofArray(arr,0,n-1);
}