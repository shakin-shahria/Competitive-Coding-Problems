#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Item {

    int item_number;
    double weight;
    double value;
    double value_weight_ratio;
};

bool compare(Item &left, Item &right){
    if(left.value_weight_ratio > right.value_weight_ratio) return true;
    else return false;
}


double fractional_knapsack(Item item[],int n, int capacity){

    // step 1 value_weight_ratio calculate
    for(int i=0;i<n;i++){
        item[i].value_weight_ratio = item[i].value/item[i].weight;
    }

    //step 2 sorting 

   sort (item,item+n,compare);
  
   int profit =0;
   
   cout<<"Supplies Picked: "<<endl;
   // step 3 selecting the item based on the sequence of step 2

   for(int i=0; i <n; i++){

     
       if(capacity>=item[i].weight){
        capacity -= item[i].weight;
        profit += item[i].value;

        cout <<item[i].item_number<<"(completely)"<<endl;

       }

       else{
               profit += (capacity*item[i].value_weight_ratio);

               capacity=0;
               cout<<item[i].item_number<<"(partially)"<<endl;
       }

       if(capacity == 0){
          break;
       }

       
       





   }
   cout<<endl;

   return profit;




}

int main(){
    int n = 5;
    Item item[n]={
        {1,50,200,0},
        {2,20,100,0},
        {3,30,120,0},
        {4,10,60,0},
        {5,40,150,0}
    };
    int capacity = 60;
    double result = fractional_knapsack(item,n,capacity);
    cout<<"Total Value: "<<result<<endl;
    return 0;

}