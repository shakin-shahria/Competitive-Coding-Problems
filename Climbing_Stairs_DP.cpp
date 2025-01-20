#include<iostream>
#include<bits/stdc++.h>
#define MAX 100
#define NOT_SET -1
using namespace std;

int cache[MAX+1];

int ways(int n){

if(n==1 && n==2) return 1;
if (cache[n]!=NOT_SET) return cache[n];

else{
int left = ways(n-1);
int right = ways(n-2);
int result = left+right;
cache[n]= result;
return result;
}




}

int main(){

int stair_length = 4;
int n =2;
int steps[n] = {1,2};
memset (cache, NOT_SET, sizeof(cache));
for (int i=0; i<n; i++){
    cout<< cache[i]<<" ";
}
cout<<endl;
ways(4);


for (int i=0; i<n; i++){
    cout<< cache[i]<<" ";
}

}