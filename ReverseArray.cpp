#include <iostream>
using namespace std;

// Function to reverse the array in-place using divide and conquer
void reverseArray(int arr[], int low, int high) {
    if (low >= high) {
        return; // Base case: When low crosses high, stop
    }
    // Swap the elements at the current low and high indices
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;

    // Recur for the remaining array
    reverseArray(arr, low + 1, high - 1);
}

void printArray(int arr[],int n){
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

   
}

int main() {
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
     printArray(arr,n);
     cout<<"After Reversing Array"<<endl;
     reverseArray(arr, 0, n - 1); // Reverse the array
     printArray(arr,n);

   

    return 0;
}
