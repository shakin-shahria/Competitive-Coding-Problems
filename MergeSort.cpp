#include<iostream>
using namespace std;
#define INFINITY 0x7F7F7F7F

void combine(int arr[],int low,int mid,int high){
     int L[mid-low+1+1];
     int R[high-mid+1+1+1];

     int idx =0;

     for(int i=low;i<=mid;i++){
         L[idx++]= arr[i];
     }
     L[idx]=INFINITY;

    idx =0;

     for(int i=mid+1;i<=high;i++){
         R[idx++]= arr[i];
     }
     R[idx]=INFINITY;


     int i=0;
     int j=0;
     idx=low;

     while(L[i]!=INFINITY || R[j]!=INFINITY){
            
            if(L[i]<R[j]){
                arr[idx] = L[i];
                i++;
            }
            else{
                arr[idx] = R[j];
                j++;
            }
            idx++;
     }
}


void merge_sort(int arr[],int low, int high){
    if(low==high){
        return;
    }
    else{
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        combine(arr,low,mid,high);
    }
}





void PrintArray(int arr[],int n){
    cout<<"Array Elements: "<< endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;
}


// void PrintArray(int arr[], int n)
// {
//     printf("The elements of the array: ");
//     for(int i=0; i<n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }











int main(){
    int n= 5;
    int arr[n]={5,4,3,2,1};
    PrintArray(arr,n);
    merge_sort(arr,0,n-1);
    PrintArray(arr,n);
    return 0;

}