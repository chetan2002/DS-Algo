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
    	for(auto &c: v) {
    		cin>>c;
    	}
    	reverse(v.begin(), v.end());
    	ll ans = 0;
    	ll i = 1;
    	ll val = v[0];
    	while(i<n) {
    		for(int k=i;k<n and k<2*i; k++) {
    			if(v[k]!=val) {
    				ans++;
    				break;
    			}
    		}
	   		i = 2*i;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}