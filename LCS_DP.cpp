#include <bits/stdc++.h>
#define MAX 100
#define NOT_SET -1
using namespace std;


int cache[MAX+1][MAX+1];

int lcs(string X, string Y, int m, int n) {
    if (cache[m][n] != NOT_SET) 
        return cache[m][n];

    if (m == 0 || n == 0) 
        return cache[m][n] = 0;

    if (X[m-1] == Y[n-1]) 
        return cache[m][n] = 1 + lcs(X, Y, m-1, n-1);

    return cache[m][n] = max(lcs(X, Y, m-1, n), lcs(X, Y, m, n-1)); 
}

int main() {
    string X = "ABCDGH";
    string Y = "AEDFHRABCD";
    int m = X.length();
    int n = Y.length();

    memset(cache, NOT_SET, sizeof(cache)); 

    int result = lcs(X, Y, m, n);

    cout << "Length of LCS is " << result << endl;

    return 0;
}