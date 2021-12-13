#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n, k;
    	cin>>n>>k;
    	vector<ll> v(n);
    	for(auto &c: v) {
    		cin>>c;
    	}
    	unordered_map<ll, ll> mp;
    	for(auto c: v) {
    		mp[c]++;
    	}
    	bool val = true;
    	ll MaxF = 0;
    	for(auto c: mp) {
    		if(c.second>k) {
    			val = false;
    		}
    		MaxF = max(c.second, MaxF);
    	}
    	if(val == false) {
    		cout<<"-1"<<endl;
    		continue;
    	}
    	if(k==MaxF) {
    		sort(v.begin(), v.end(), greater<ll>());
    	}else{
    		
    	}
    	for(auto c: v) {
    		cout<<c<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}