#include<iostream>
using namespace std;

int mergeAndCount(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];

    // Copy data to temporary arrays
    for(int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for(int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low, invCount = 0;

    // Merge the arrays and count inversions
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            invCount += (n1 - i);  // All remaining elements in the left array are greater than right[j]
        }
    }

    // Copy the remaining elements
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];

    return invCount;
}

int mergeSortAndCount(int arr[], int low, int high) {
    int invCount = 0;
    if(low < high) {
        int mid = (low + high) / 2;

        invCount += mergeSortAndCount(arr, low, mid);
        invCount += mergeSortAndCount(arr, mid + 1, high);

        invCount += mergeAndCount(arr, low, mid, high);
    }
    return invCount;
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int n = 5;

    int result = mergeSortAndCount(arr, 0, n - 1);
    cout << "Number of inversions: " << result << endl;

    return 0;
}
