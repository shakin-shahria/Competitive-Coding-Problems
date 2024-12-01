#include<iostream>
using namespace std;

struct Digit
{
    int even_digit;
    int total_digit;
};

typedef struct Digit Digit;

Digit count_digit_and_even_digit(int n)
{
    if(n>=0 && n<=9)
    {
        if(n%2==0) return {1, 1};
        else return {0, 1};
    }
    else
    {
        int last_digit = n%10;
        Digit friend_answer = count_digit_and_even_digit(n/10);

        if(last_digit%2==0)
        {
            return {friend_answer.even_digit+1, friend_answer.total_digit+1};
        }
        else
        {
            return {friend_answer.even_digit, friend_answer.total_digit+1};
        }
    }
}

int main()
{
    Digit answer = count_digit_and_even_digit(125647);
    cout << answer.even_digit << " " << answer.total_digit << endl;
    return 0;
}
