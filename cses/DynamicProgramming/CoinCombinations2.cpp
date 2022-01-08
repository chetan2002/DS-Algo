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
 	vector<vector<int>> dp(n, vector<int>(k+1, 0));
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
 	for(int i=0; i<n;  i++) {
        for(int j=1; j<=k; j++) {
            if(j>=v[i]) {
                dp[i][j] = dp[i][j-v[i]]%MOD;
            }
            if(i>0) {
                dp[i][j] += dp[i-1][j]%MOD;
            }
            dp[i][j] = dp[i][j]%MOD;
        }
    }
 	cout<<dp[n-1][k]<<endl;

    return 0;
}