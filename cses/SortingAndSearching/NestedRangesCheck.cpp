#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool what(vector<ll> &a, vector<ll> &b) {
	if(a[0]==b[0]) {
		return a[1]>b[1];
	}
	return a[0]<b[0];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;cin>>n;
	vector<vector<ll>> v;
	for(int i=0; i<n; i++) {
		ll a, b;
		cin>>a>>b;
		v.push_back({a, b, i});
	}
	sort(v.begin(), v.end(), what);
	vector<ll> sub(n);
	vector<ll> sup(n);
	ll maxi = 0;
	priority_queue<pair<ll, ll>> pq;
	for(auto c: v) {
		if(c[1]<=maxi) {
			sub[c[2]] = 1;
		}
		maxi = max(maxi, c[1]);
		while(!pq.empty() and pq.top().first>=c[1]) {
			sup[pq.top().second] =1 ;
			pq.pop();
		}
		pq.push({c[1], c[2]});
	}
	for(auto c: sup) {
		cout<<c<<" ";
	}
	cout<<endl;
	for(auto c: sub) {
		cout<<c<<" ";
	}
	cout<<endl;
    return 0;
}