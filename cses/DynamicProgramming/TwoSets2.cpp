#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD = 1e9+7;

ll answer(ll n) {
 	ll sum = n*(n+1)/2;
	if(sum%2!=0) {
 		return 0;
 	}
 	sum/=2;

 	vector<ll> dp(sum+1, 0);
 	dp[0] = 1;
	for(ll i=1; i<=n; i++) {
		for(ll j=sum; j>=0; j--) {
			if(j>=i) {
				dp[j] += dp[j-i];
				dp[j] %= (2*MOD);
			}
		}		
	}
	return (dp[sum]/=2)%MOD;
	// return dp[sum]%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n; 
 	cin>>n;   

 	cout<<answer(n)<<endl;
    return 0;
}