#include<bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int id;
    double cgpa;
};

struct Compare {
    bool operator()(Student left, Student right) {
        if(left.cgpa>right.cgpa)
            return true;
        else
            return false;
    }
};

int main()
{
    priority_queue< Student, vector< Student >, Compare > studentPQ;

    studentPQ.push({"Halim", 1, 3.5});
    studentPQ.push({"Dalim", 2, 4.0});
    studentPQ.push({"Mughlai", 3, 3.9});

    cout << studentPQ.top().name << endl;

    return 0;
}

