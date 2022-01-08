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
    	ll first = v[0];
    	for(int i=2; i<n; i+=2) {
    		first = __gcd(v[i], first);
    	}
    	ll second = v[1];
    	for(int i=3; i<n; i+=2) {
    		second = __gcd(v[i], second);
    	}
    	if(first==second) {
    		cout<<0<<endl;
    	}else{

    		ll val1 = 0;
    		bool pos1 = true;
    		
			for(int i=0; i<n; i+=2) {
				if(v[i]%second==0) {
					pos1 = false;
					break;
				}
			}
			if(pos1) {
				val1 = second;
			}
			
			ll val2 = 0;
			bool pos2 = true;
			for(int i=1; i<n; i+=2) {
				if(v[i]%first==0) {
					pos2 = false;
					break;
				}
			}
			if(pos2) {
				val2 = first;
			}
    		cout<<max(val1, val2)<<endl;
    	}
    }
    return 0;
}