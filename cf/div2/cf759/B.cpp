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
    	for(auto &c: v) {
    		cin>>c;
    	}
    	ll maxi = v[n-1], count =0;
    	for(int i=n-2; i>=0; i--) {
    		if(v[i]>maxi) {
    			maxi =v[i];
    			count++;
    		}
    	}
    	cout<<count<<endl;
    }
    return 0;
}