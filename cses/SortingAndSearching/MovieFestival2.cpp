#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool comp(pair<ll, ll> p1, pair<ll, ll> p2) {
	if(p1.second == p2.second) {
		return p1.first<p2.first;
	}
	return p1.second<p2.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, k;
 	cin>>n>>k;
 	vector<pair<ll,ll>> v;
 	for(ll i=0; i<n; i++) {
 		ll a, b;
 		cin>>a>>b;
 		v.push_back({a,b});
 	}
 	sort(v.begin(), v.end(), comp);
 	multiset<ll> pq;
 	for(int i=0; i<k; i++) {
 		pq.insert(0);
 	}
 	ll count =0 ;
 	for(auto c: v) {
 		auto it = pq.upper_bound(c.first);
 		if(it == pq.begin() ) continue;
 		--it;
 		pq.erase(it);
 		pq.insert(c.second);
 		count++;
 	}
 	cout<<count<<endl;
    return 0;
}