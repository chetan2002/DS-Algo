#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	vector<ll> dp(n+1, INT_MAX);
 	dp[0] = 0;   
 	for(int i=1; i<=n; i++) {
 		int val = i;
 		while(val>0) {
 			dp[i] = min(dp[i], 1 + dp[i-val%10]);
 			val/=10;
 		}
 	}
 	cout<<dp[n]<<endl;
    return 0;
}