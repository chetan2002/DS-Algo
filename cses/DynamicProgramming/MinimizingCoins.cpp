#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_set<ll, custom_hash> v;
vector<ll> dp;

ll minCoins(ll X) {
	dp.clear();
	dp.resize(X+1, INT_MAX);
	dp[0] = 0;
	for(int i=0; i<=X; i++) {
		for(auto c: v) {
			if(i-c>=0) {
				dp[i] = min(dp[i], dp[i-c]+1);
			}
		}
	}
	return dp[X]==INT_MAX?-1:dp[X];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, X;
 	cin>>n>>X;
 	for(int i=0; i<n; i++) {
 		ll val;
 		cin>>val;
 		v.insert(val);
 	}   
 	cout<<minCoins(X)<<endl;
    return 0;
}