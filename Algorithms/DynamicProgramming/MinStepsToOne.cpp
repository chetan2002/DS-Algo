#include<bits/stdc++.h>
using namespace std; 
#define ll long long int

// you can take 1 step , or 2*n steps if n%2==0 and 3*n steps if n%3 == 0

//recursive approach
ll recursiveMinStepsToOne(ll n){
    if(n<=1){
        return 0;
    }
    ll op1 , op2 , op3 ; 
    op1 = op2 = op3 = INT_MAX;
    op1 = recursiveMinStepsToOne(n-1) +1;
    if(n%2==0){
        op2 = recursiveMinStepsToOne(n/2)+ 1;
    }
    if(n%3 == 0){
        op3 = recursiveMinStepsToOne(n/3) + 1;
    }
    return min(op1 , min(op2 , op3));
}

//top down approach -> recursive memoisation
ll topDownMinStepsToOne(ll* dp , ll n){
    if(n<=1){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    ll op1 , op2 , op3;
    op1 = op2 = op3 = INT_MAX;
    op1 = topDownMinStepsToOne(dp , n-1)+1;
    if(n%2==0){
        op2 = topDownMinStepsToOne(dp , n/2) +1 ;
    }
    if(n%3 == 0){
        op3 = topDownMinStepsToOne(dp , n/3)+1;
    }

    return min(min(op1 , op2) , op3);
}

//Bottom up approach -> iterative tabulation
ll bottomUpMinStepsToOne(ll n){
    ll* dp = new ll[n+1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2 ; i<=n ; i++){
        int op1 , op2 , op3 ;
        op1 = op2 = op3 = INT_MAX;
        op1 = dp[i-1] +1;
        if(i%2==0){
            op2 = dp[i/2]+1;
        }
        if(i%3 == 0){
            op3 = dp[i/3]+1;
        }
        dp[i] = min(op1 , min(op2 , op3));
    }
    return dp[n];
}

int main(){
    ll n; 
    cin>> n;

    ll *dp = new ll[n+1];
    for(int i=0 ; i<=n ; i++){
        dp[i] = -1;
    }
    cout<<topDownMinStepsToOne(dp , n)<<endl;
    cout<<bottomUpMinStepsToOne(n)<<endl;
    //for(int i = 1 ; i <= n ; i++){
        cout<<recursiveMinStepsToOne(n)<<endl;
    //}

    delete []dp;
    return 0;
}