#include<bits/stdc++.h>
using namespace std;
#define ll uint64_t
vector<vector<ll>> v;

ll answer() {
	map<ll, ll> mp;
	for(auto c: v) {
		auto value = mp.lower_bound(c[0]);
		ll previous =0;
		if(value!=mp.begin()) {
			--value;
			previous = value->second;
		}
		value = mp.upper_bound(c[1]);
		if(value!=mp.begin()) {
			--value;
			mp[c[1]] = value->second;			
		}
		mp[c[1]] = max(mp[c[1]], previous + c[2]);
	}
	auto value = mp.end();
	--value;
	return value->second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n; 
 	v.resize(n);
 	for(auto &c: v) {
 		c.resize(3);
 		cin>>c[0]>>c[1]>>c[2];
 	}
 	sort(v.begin(), v.end());
 	cout<<answer()<<endl;
    return 0;
}