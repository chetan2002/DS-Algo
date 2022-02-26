#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, k;
vector<vector<ll>> vp;
set<pair<ll,ll>> s;


void answer() {
	sort(vp.begin(), vp.end(), [](vector<ll> &a, vector<ll> &b) {
		if(a[1]==b[1]) {
			return a[0]<b[0];
		}
		return a[1]>b[1];
	});
	ll sum =0;
	vector<pair<ll, ll>> ans;
	for(auto c: vp) {
		auto it = s.lower_bound({c[0], 0});
		if(it == s.end()) {
			continue;
		}else {
			sum += c[1];
			ans.push_back({c[2], (*it).second});
			s.erase(it);
		}
	}
	cout<<ans.size()<<" "<<sum<<endl;
	for(auto c: ans) {
		cout<<c.first<<" "<<c.second<<endl;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vp.resize(n);
    for(ll i=1; i<=n; i++) {
    	ll a, b; cin>>a>>b;
    	vp[i-1].push_back(a);
    	vp[i-1].push_back(b);
    	vp[i-1].push_back(i);
    }
    cin>>k;
    for(ll i=1; i<=k; i++) {
    	ll val;cin>>val;
    	s.insert({val, i});
    }
    answer();
    return 0;
}