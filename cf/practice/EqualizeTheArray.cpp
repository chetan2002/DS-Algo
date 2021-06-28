#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n; 
    	cin>>n;
    	vector<ll> v(n);
    	for(int i=0;i<n;i++){
    		cin>>v[i];
    	}
    	unordered_map<ll,ll> mp;
    	for(auto c: v){
    		mp[c]++;
    	}

    	ll low = INT_MAX;
    	for(auto c: mp){
    		low = min(low,c.second);
    	}

    	ll count = 0;
    	for(auto c: mp){
    		count += (c.second-low);
    	}
    	cout<<count<<endl;
    }
    return 0;
}