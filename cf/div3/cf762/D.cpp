#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool comp(vector<ll> &a, vector<ll> &b) {
	if(a.size()>1) {
		return a[1]>b[1];
	}
	return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll m, n;
    	cin>>m>>n;

    	vector<vector<pair<ll, ll>>> v(n);
    	for(int i=0; i<m; i++) {
    		for(int j=0; j<n; j++) {
    			ll val;cin>>val;
    			v[j].push_back({val, i});
    		}
    	}
    	for(auto &c: v) {
    		sort(c.begin(), c.end());
    	}
    	unordered_set<ll> s;
    	for(auto c: v) {
    		for(auto a: c) {
    			s.insert()
    		}
    	}
    }
    return 0;
}