#include<iostream>
using namespace std;
#define ll unsigned long long int

ll findFib(ll n){
    if(n <=1 ){
        return n;
    }
    return findFib(n-1) + findFib(n-2);
}

//top down = memoisation + recursion

ll topDown(ll n , ll *dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = topDown(n-1 , dp) + topDown(n-2 , dp);
}


//bottom up  = iterative solution
ll bottomUp(ll n){
    ll *dp = new ll[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2 ; i<=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    ll ans = dp[n];
    delete []dp;
    return ans;
}
int main(){
    ll n;
    cin>>n;
    ll *dp = new ll[n+1];
    for(int i=0 ; i<=n ; i++){
        dp[i] = -1;
    }
    cout<<bottomUp(n)<<endl;
    cout<<topDown(n , dp)<<endl;
   // cout<<findFib(n)<<endl;
    return 0;
}