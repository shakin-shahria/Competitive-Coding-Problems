#include <iostream>
using namespace std;

// Struct to store minimum and maximum values along with their indices
struct MinMaxIndices {
    int minimum;
    int minimumIndex;
    int maximum;
    int maximumIndex;
};

// Function to find both minimum and maximum elements with indices
MinMaxIndices findMinimumMaximumIndices(int arr[], int n) {
    if (n == 1) {
        return {arr[0], 0, arr[0], 0};
    } else {
        int lastElement = arr[n - 1];
        MinMaxIndices result = findMinimumMaximumIndices(arr, n - 1);

        if (lastElement < result.minimum) {
            result.minimum = lastElement;
            result.minimumIndex = n - 1;
        }
        if (lastElement > result.maximum) {
            result.maximum = lastElement;
            result.maximumIndex = n - 1;
        }
        return result;
    }
}

int main() {
    int n = 10;
    int arr[n] = {15, 14, 13, 11, 10, 8, 16, 45, 18, 25};

    MinMaxIndices resultIndices = findMinimumMaximumIndices(arr, n);
    cout << "Minimum: " << resultIndices.minimum
         << " MinimumIndex: " << resultIndices.minimumIndex
         << " Maximum: " << resultIndices.maximum
         << " MaximumIndex: " << resultIndices.maximumIndex ;

    return 0;
}
