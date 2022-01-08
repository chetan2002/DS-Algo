#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD = 1e9+7;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, k;
 	cin>>n>>k;
 	vector<ll> v(n);
 	for(auto &c: v) {
 		cin>>c;
 	}
 	sort(v.begin(), v.end());
 	vector<ll> dp(k+1);
 	dp[0] = 1;
 	for(ll i=1; i<=k; i++) {
 		for(auto c: v) {
 			if(c<=i) {
 				dp[i] += dp[i-c];
 				dp[i] = dp[i]%MOD;
 			}
 		}
 	}
 	cout<<dp[k]<<endl;

    return 0;
}