#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> dp;

ll answer(ll n, ll m) {
	if(n==m) {
		return 0;
	}
	if(n==1) {
		return m-1;
	}
	if(m==1) {
		return n-1;
	}
	if(dp[n][m]!=-1) {
		return dp[n][m];
	}
	ll val = INT_MAX;
	// n
	for(int i=1; i<=n/2; i++) {
		val = min(val, 1 + answer(i, m) + answer(n-i, m));
	}
	for(int i=1; i<=m/2; i++) {
		val = min(val, 1 + answer(n, i) + answer(n, m-i));
	}
	return dp[n][m] = val;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, m;
 	cin>>n>>m;
 	dp.resize(n+1, vector<ll>(m+1, -1));
 	cout<<answer(n, m)<<endl;
    return 0;
}