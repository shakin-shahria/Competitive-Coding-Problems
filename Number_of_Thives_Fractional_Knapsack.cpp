#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int item_number;
    double weight;
    double value;
    double value_weight_ratio;
};



bool compare(Item &left, Item &right)
{
   
    if(left.value_weight_ratio>right.value_weight_ratio) return true;
    else return false;
}


double fractional_knapsack(Item items[], int n, int capacity)
{
     
    /// step 1: Find the value-weight ratio for each item

      for(int i=0; i<n; i++)
    {
        items[i].value_weight_ratio = items[i].value/items[i].weight;
    }


    /// step 2: Sort the items based on value-weight ratio (descending order)
    sort(items, items+n, compare);

    /// step 3: Start picking the items based on the sequence of step 2 until you have the capacity

    double profit = 0;

    cout << "Picked Items: ";
    for(int i=0; i<n; i++)
    {
        if(items[i].value==0 && items[i].weight==0)
            continue;

        if(capacity>=items[i].weight)
        {
            capacity -= items[i].weight;
            profit += items[i].value;

            items[i].weight = 0;
            items[i].value = 0;

            cout << items[i].item_number << " ";
        }
        else
        {
            profit += (capacity * items[i].value_weight_ratio);

            items[i].value -= (capacity *items[i].value_weight_ratio );

            items[i].weight -= capacity;




            capacity = 0;

            cout << items[i].item_number << "(F) ";
        }


        if(capacity==0)
            break;
    }
    cout << endl;
    return profit;
}


void printItems(Item items[], int n)
{
    cout << endl;
    for(int i=0; i<n; i++)
    {
        cout << items[i].item_number << " " << items[i].value << " " << items[i].weight << endl;
    }
    cout << endl;
}

int main()
{

    int n = 6;
    Item items[n] = {
        {1, 10, 60},
        {2, 20, 100},
        {3, 30, 120},
        {4, 40, 80},
        {5, 50, 90},
        {6, 60, 150}
    };
    int capacity = 50;

    cout << "Thief 1: \n";
    double result = fractional_knapsack(items, n, capacity);
    cout << "Total Profit: " << result << endl;

    printItems(items, n);

    int thief = 2;

    while(result!=0)
    {
        cout << "Thief " << thief << " : \n";
        result = fractional_knapsack(items, n, capacity);
        cout << "Total Profit: " << result << endl;

        printItems(items, n);

        thief++;

    }
    return 0;
}

