#include<iostream>
using namespace std;

int findMinimum(int arr[], int n)
{
    if(n==1)
    {

        return arr[0];
    }
    else
    {
        int lastElement = arr[n-1];
        int minimumInRestOftheArray = findMinimum(arr, n-1);
        if(lastElement<minimumInRestOftheArray) return lastElement;
        else return minimumInRestOftheArray;
    }
}

int main()
{
    int n = 10;
    int arr[n] = {15, 14, 13, 11, 10, 8, 16, 45, 18, 25};
    int result = findMinimum(arr, n);
    printf("%d\n", result);
    return 0;
}
