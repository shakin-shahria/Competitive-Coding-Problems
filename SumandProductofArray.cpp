#include<iostream>
using namespace std;

struct SumandProductofArray
{
    int sumofArray;
    int productofArray;
};

//typedef struct SumandProductofArray;

SumandProductofArray finding_sum_and_product(int arr[],int n){

      if(n==1){
        return {arr[0],arr[0]};
      }
      else{
             int lastElement = arr[n-1];
             SumandProductofArray result = finding_sum_and_product(arr,n-1);
             return {result.sumofArray+lastElement,result.productofArray*lastElement};

      }

}

int main(){
    int n = 3;
    int arr[n]={2,3,4};
    SumandProductofArray answer = finding_sum_and_product(arr,n);
    cout<<"Sum of the Array: "<<answer.sumofArray<<endl;
    cout<<"Product of the Array: "<<answer.productofArray<<endl;

}
