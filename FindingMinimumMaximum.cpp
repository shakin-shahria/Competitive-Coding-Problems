#include<iostream>
using namespace std;

struct MinMax
{
    int minimum;
    int maximum;
};

typedef struct MinMax MinMax;

MinMax findMinimumMaximum(int arr[], int n)
{
    if(n==1)
    {
        return {arr[0], arr[0]};
    }
    else
    {
        int lastElement = arr[n-1];
        MinMax restOfTheArrayMinMax = findMinimumMaximum(arr, n-1);

        if(lastElement<restOfTheArrayMinMax.minimum)
        {
            return {lastElement, restOfTheArrayMinMax.maximum};
        }
        else if(lastElement>restOfTheArrayMinMax.maximum)
        {
            return {restOfTheArrayMinMax.minimum, lastElement};
        }
        else
            return restOfTheArrayMinMax;
    }
}



int main()
{
    int n = 10;
    int arr[n] = {15, 14, 13, 11, 10, 8, 16, 45, 18, 25};
    MinMax result = findMinimumMaximum(arr, n);
    printf("Minimum: %d Maximum: %d\n", result.minimum, result.maximum);
}
