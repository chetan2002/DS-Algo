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
    	vector<ll> k(n);
    	for(auto &c: k) {
    		cin>>c;
    	}
    	vector<ll> h(n);
    	for(auto &c: h) {
    		cin>>c;
    	}

    	ll sum =0;
    	ll prevVal = 0, s = 0;
    	for(int i=0; i<n; i++) {
    		if(h[i]<=k[i]-s) {
    			ll value = h[i]*(h[i]+1)/2;
    			sum+=value;
    			prevVal = h[i];
    			s = k[i];
    		}else {
    			ll value = (prevVal+(k[i]-s))*(prevVal+k[i]-s+1)/2;
    			sum += value - (prevVal*(prevVal+1))/2;
    			prevVal = prevVal + k[i] - s;
    			s = k[i];
    		}
    	}
    	cout<<sum<<endl;
    }
    return 0;
}