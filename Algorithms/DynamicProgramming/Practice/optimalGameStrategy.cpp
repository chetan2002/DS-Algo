//https://hack.codingblocks.com/app/contests/2022/1255/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll dp[5005][5005];

ll recursiveSol(ll *arr , ll i , ll j ){
    if(j<i){
        return 0;
    }
    if(i==j){
        return dp[i][j] = arr[i];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll val1 = arr[i] + min(recursiveSol(arr , i+2 , j) , recursiveSol(arr , i+1 , j-1));
    ll val2 = arr[j] + min(recursiveSol(arr , i , j-2) , recursiveSol(arr , i+1 , j-1));

    return dp[i][j] = max(val1 , val2);
}

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp , -1 , sizeof(dp));
    cout<<recursiveSol(arr , 0 , n-1)<<endl;
    return 0;
}