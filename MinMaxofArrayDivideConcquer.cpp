#include<iostream>
using namespace std;

// Struct to hold minimum and maximum values
struct MinMax {
    int minimum;
    int maximum;
};

// Function to find min and max using divide and conquer
MinMax findMinMax(int arr[], int low, int high) {
    // Base case: If there's only one element
    if (low == high) {
        return {arr[low], arr[low]};
    }

    

    // Divide the array into two parts
    int mid = (low + high) / 2;
    MinMax left = findMinMax(arr, low, mid);
    MinMax right = findMinMax(arr, mid + 1, high);

    // Combine results
    MinMax result;
    result.minimum = (left.minimum < right.minimum) ? left.minimum : right.minimum;
    result.maximum = (left.maximum > right.maximum) ? left.maximum : right.maximum;

    return result;
}

// Main function
int main() {
    int n = 7;
    int arr[n] = {7, 2, 8, 1, 4, 10, 3};
    

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "Minimum: " << result.minimum << endl;
    cout << "Maximum: " << result.maximum << endl;

    return 0;
}
