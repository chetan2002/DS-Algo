#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define Lim 5000



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> v;
    v.push_back(0);
	for(ll i=1;i<=Lim;i++){
		ll ans = (i*(i+1))/2;
		v.push_back(ans);
	}
	unordered_map<ll , ll> mp;
	for(ll i=0;i<v.size();i++){
		for(ll j=i+1;j<v.size();j++){
			mp[v[j]-v[i]]++;
		}
	}
    ll t;
    cin>>t;
    for(ll l=0;l<t;l++){
    	ll value;
    	cin>>value;
    	ll count = mp[value];
		cout<<"Case #"<<l+1<<": "<<count<<endl;
    }
    return 0;
}