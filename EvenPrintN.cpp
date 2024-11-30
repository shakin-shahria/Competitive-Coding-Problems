#include<iostream>
using namespace std;

void printEvenOnly(int n)
{
    if(n==0)
    {
        return;
    }
    else
    {
        printEvenOnly(n-1);

        if(n%2==0)
            printf("%d ", n);
    }
}

int main()
{
    printEvenOnly(25);
    return 0;
}
