//https://hack.codingblocks.com/app/contests/2022/128/problem


//constraints of this problem are high and hence it is difficult to make an array of that size
//so we use map
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
// unordered_map<ll,ll> mp;
// ll recur(ll n){
//     if(n==0 || n==1){
//         return mp[n] = n;
//     }
//     if(mp[n]){
//         return mp[n];
//     }
    
//     ll op1 = recur(n/2 );
//     ll op2 = recur(n/3);
//     ll op3 = recur(n/4);

//     return mp[n] = max(n , op1+op2+op3);

// }
ll bottomUp(ll n){
    unordered_map<ll,ll> mapa;
    mapa[0] = 0;
    for(ll i=1 ; i<=n;i++){
        mapa[i] = max(i , mapa[i/2]+mapa[i/3] + mapa[i/4]);    
    }
    return mapa[n];
}
int main(){
    ll n;
    cin>>n;
    // ll dp[100000001]={0};
    //memset(dp , -1 , sizeof(dp));
    // cout<<recur(n)<<endl;
    cout<<bottomUp(n)<<endl;
    return 0;
}