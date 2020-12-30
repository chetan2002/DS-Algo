//Problem: //https://leetcode.com/problems/numbers-with-same-consecutive-differences/
//solution: https://ide.codingblocks.com/s/396969

#include<bits/stdc++.h>
using namespace std;


void consecutiveDifference(int n , int k , int d , int sum){
    if(n==1){
        cout<<sum*10 + d<<" ";
        return;
    }
    sum = sum*10 + d;
    if(d-k>=0 and d-k<=9){
        consecutiveDifference(n-1 , k , d-k , sum);
    }
    if(d+k>=0 and d+k<=9 and k>0){
        consecutiveDifference(n-1 , k , d+k , sum);
    }
}

int main(){
    int n , k;
    cin>>n>>k;

    for(int i=1;i<=9;i++){
        consecutiveDifference(n , k , i , 0 );
    }

    return 0;
}
