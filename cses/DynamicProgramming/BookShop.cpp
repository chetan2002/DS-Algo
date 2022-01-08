#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, k;
vector<ll> w;
vector<ll> v;

ll answer() {
	vector<ll> dp(k+1, 0);
	for(ll i=0; i<n; i++) {
		for(ll j=k; j>=0; j--) {
			if(w[i]<=j) {
				dp[j] = max(dp[j], v[i] + dp[j-w[i]]);
			}
		}
	}
	return dp[k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	cin>>n>>k;
 	w.resize(n), v.resize(n);
 	for(auto &c: w) {
 		cin>>c;
 	}
 	for(auto &c: v) {
 		cin>>c;
 	}

 	cout<<answer()<<endl;
    return 0;
}