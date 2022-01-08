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
    	ll l =1 + v[0];
    	bool died = false;
    	for(int i=1; i<n; i++) {
    		if(v[i]==1) {
    			if(v[i-1]==1) {
    				l+=5;
    			}else{
    				l++;
    			}
    		}
    		if(v[i]==0 and v[i-1]==0) {
    			died = true;
    			break;
    		}
    	}
    	if(!died){
	    	cout<<l<<endl;
    	}else{
    		cout<<"-1"<<endl;
    	}
    }
    return 0;
}