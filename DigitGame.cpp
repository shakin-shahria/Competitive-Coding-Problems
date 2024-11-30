#include<iostream>
using namespace std;
int countDigit(int n)
{
    if(n>=0 && n<=9)
    {
        return 1;
    }
    else
    {
        /// int lastDigit = n%10;

        int restDigitsCount = countDigit(n/10);
        return restDigitsCount + 1;
    }
}


int countEvenDigit(int n)
{
    if(n>=0 && n<=9)
    {
        if(n%2==0)
            return 1;
        else
            return 0;
    }
    else
    {
        int lastDigit = n%10;

        int restEvenDigitsCount = countEvenDigit(n/10);

        if(lastDigit%2==0)
            return restEvenDigitsCount + 1;
        else
            return restEvenDigitsCount;
    }
}
int main()
{
    int n = 125457;

    cout << "The number of digits: "<<countDigit(n) << endl;
    cout << "The number of even digits: "<<countEvenDigit(n) << endl;
    return 0;
}
