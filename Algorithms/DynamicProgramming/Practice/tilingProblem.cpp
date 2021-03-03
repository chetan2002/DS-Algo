#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[50005];

ll topDown(ll n , ll m ){
    if(n==0){
        return dp[n]=0;
    }
    if(n==m){
        return dp[n]=2;
    }
    if(n<m){
        return dp[n]=1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    ll a = topDown(n-m , m);
    ll b = topDown(n-1 , m);

    return dp[n]=a+b;
}

ll bottomUP(ll n , ll m){
    dp[0]=0;
    for(int i=0;i<=n;i++){
        if(i<m){
            dp[i]=1;
        }else
        if(i>m){
            dp[i] = dp[i-m]+dp[i-1];
        }else{
            dp[i]=2;
        }
    }
    return dp[n];
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        memset(dp , -1 , sizeof(dp));
        cout<<topDown(n , m)<<endl;
        cout<<bottomUP(n,m)<<endl;
    }
    return 0;
}