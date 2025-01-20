#include <bits/stdc++.h>
#define MAX 100
#define NOT_SET -1
using namespace std;

//const int INF = 0x7f7f7f7f;

int cache[MAX + 1][MAX + 1]; // DP cache for storing subproblem results

struct Item {
    int item_number;
    int weight;
    int value;
};

// Function to solve the 0/1 Knapsack Problem using caching
int knapsack(int i, int capacity, Item items[]) {
    if (i < 0 || capacity <= 0) return 0; // Base case

    if (cache[i][capacity] != NOT_SET) return cache[i][capacity]; // Use cached value

    int exclude = knapsack(i - 1, capacity, items); // Exclude current item
    int include = 0;
    if (items[i].weight <= capacity) { // Include current item if it fits
        include = items[i].value + knapsack(i - 1, capacity - items[i].weight, items);
    }

    cache[i][capacity] = max(exclude, include); // Store the result in the cache
    return cache[i][capacity];
}


void find_picked_items(int n, int capacity, Item items[]) {
    cout << "Picked Items: ";
    int w = capacity;

    for (int i = n - 1; i >= 0 && w > 0; i--) {
        if (cache[i][w] != cache[i - 1][w]) { // Item was included
            cout << items[i].item_number << " ";
            w -= items[i].weight; // Reduce remaining capacity
        }
    }
    cout << endl;
}


int main() {
    // Number of items and knapsack capacity
    int n = 6;
    int capacity = 50;

    // Items array (item_number, weight, value)
    Item items[n] = {
        {1, 10, 60},
        {2, 20, 100},
        {3, 30, 120},
        {4, 40, 80},
        {5, 50, 90},
        {6, 60, 150}
    };

    // Initialize cache with NOT_SET
    memset(cache, NOT_SET, sizeof(cache));

    // Solve the knapsack problem
    int max_profit = knapsack(n - 1, capacity, items);

    // Output the results
    cout << "Total Profit: " << max_profit << endl;

    // Find and display the picked items
    find_picked_items(n, capacity, items);

    return 0;
}
