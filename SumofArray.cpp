#include<iostream>
using namespace std;

int sum_of_array(int arr[], int n){

       if(n==1){
        return arr[0];
       }
       else{
           int lastElement = arr [n-1];
           int rest_array_sum = sum_of_array(arr,n-1);
           return rest_array_sum+ lastElement;
       }

}

int main(){

    int n =5;
    int arr[n]={1,2,3,4,5};
    int result = sum_of_array(arr,n);
    cout<<"Sum of Array: "<<result;
}