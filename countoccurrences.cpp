#include<iostream>
using namespace std;

// Function to count occurrences of a number in the array using divide and conquer
int countOccurrences(int arr[], int low, int high, int target) {
    // Base case: Single element
    if (low == high) {
        return (arr[low] == target) ? 1 : 0;
    }

    // Divide the array into two parts
    int mid = (low + high) / 2;

    // Recursively count occurrences in the left and right halves
    int leftCount = countOccurrences(arr, low, mid, target);
    int rightCount = countOccurrences(arr, mid + 1, high, target);

    // Combine the results
    return leftCount + rightCount;
}

int main() {
    int n = 8; // Size of the array
    int arr[] = {1, 2, 3, 2, 4, 2, 5, 6}; // Input array
    int target = 2; // Number to count occurrences of

    // Call the function and print the result
    int result = countOccurrences(arr, 0, n - 1, target);
    cout << "The number " << target << " appears " << result << " times in the array." << endl;

    return 0;
}
