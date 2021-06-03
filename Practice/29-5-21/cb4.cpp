#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int maxn = 2048+10;
ll dp[maxn][maxn] , n ;
ll A[maxn];

ll sum(ll l, ll r) {
	return A[r] - A[l-1];
}

ll solve(ll l, ll r) {
	ll &ret = dp[l][r];
	if( ret != -1 ) return ret;
	ret = 0;
	for(ll x=l; x<r; x++) {
		if(sum(l, x) == sum(x+1, r)) // valid x
			ret = max(ret, max(solve(l, x), solve(x+1, r)) + 1);
	}
	return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--){
    	ll n; cin >> n;
		for(ll i=1; i<=n; i++) {
			cin >> A[i];
			A[i] += A[i-1];
		}
		memset(dp, -1, sizeof dp);
		cout << solve(1, n) << "\n";
    }

    return 0;
}