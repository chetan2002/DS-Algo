#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	vector<ll> v(n);
    	unordered_map<ll,ll> mp;

    	ll smallest = INT_MAX;
    	for(int i=0;i<n;i++){
    		cin>>v[i];
    		smallest = min(smallest , v[i]);
    		mp[v[i]]++;
    	}
    	cout<<v.size()-mp[smallest]<<endl;
    }
    return 0;
}