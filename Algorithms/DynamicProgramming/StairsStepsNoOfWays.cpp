#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll recursion(ll n , ll k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    ll ans = 0;
    for(int i=1;i<=k;i++){
        ans += recursion(n-i , k);
    }
    return ans;
}

ll topDown(ll n , ll k , ll* dp){
    if(n==0){
        return dp[n] = 1;
    }
    if(n<0){
        return 0;
    }

    if(dp[n]!= -1){
        return dp[n];
    }

    ll ans = 0;
    for(int i=1;i<=k;i++){
        ans += topDown(n-i , k , dp);
    }
    return dp[n] = ans;

}

//order (n*k)
ll bottomUp(ll n , ll k){
    ll dp[n+1];
    dp[0] = 1;

    for(int i=1 ; i<=n ; i++){
        ll sum = 0;
        for(int j=1 ; j<=k;j++){
            if(i>=j){
                sum+=dp[i-j];
            }
        }
        dp[i] = sum;
    }
    return dp[n];
}

//order (N)
ll bottomUpOptimised(ll n , ll k){
    ll dp[n+1];
    dp[0] = 1;
    
    ll sum=1;
    for(int i=1 ; i<=k ; i++){
        dp[i] = sum;
        sum+=dp[i];
    }

    for(int i=k+1 ; i<=n ; i++){
        sum-=dp[i-k-1];
        dp[i] = sum;
        sum+=dp[i];
    }
    return dp[n];
}

int main(){
    ll n , k;
    cin>>n>>k;

    ll dp[1009];
    memset(dp , -1 , sizeof(dp));
    cout<<bottomUp(n ,k)<<endl;
    cout<<topDown(n ,k , dp)<<endl;
    cout<<bottomUpOptimised(n , k)<<endl;
    //cout<<recursion(n , k)<<endl;

    return 0;
}