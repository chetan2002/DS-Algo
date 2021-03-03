//https://hack.codingblocks.com/app/contests/2022/146/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll answer(ll n , ll k , ll* wt , ll *val){
	ll dp[k+1];
	dp[0]=0;
	for(ll i = 1 ;i<=k;i++){
		dp[i] = 0;
		for(ll j=0;j<n;j++){
			if(i-wt[j]>=0){
				dp[i] = max(dp[i] , dp[i-wt[j]]+val[j]);
			}
		}
	}
	return dp[k];
}

int main(){
	ll n , k;
	cin>>n>>k;
	ll wt[n];
	ll val[n];
	for(ll i=0;i<n;i++){
		cin>>wt[i];
	}
	for(ll i=0;i<n;i++){
		cin>>val[i];
	}
	cout<<answer(n , k , wt , val)<<endl;
	return 0;
}