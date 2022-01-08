#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	vector<pair<ll,ll>> vp(n);
 	for(auto &c: vp) {
 		ll a, b;
 		cin>>a>>b;
 		c = {a,b};
 	}   
 	ll t = 0;
 	ll cost = 0;
 	sort(vp.begin(), vp.end());
 	for(auto c: vp) {
 		t+=c.first;
 		cost += (c.second-t);
 	}
 	cout<<cost<<endl;
    return 0;
}