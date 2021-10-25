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
    	list<ll> v;
    	for(int i=0;i<n;i++) {
    		ll val;
    		cin>>val;
    		if(i==0) {
    			v.push_back(val);
    		}else{
    			if(v.front()<val) {
    				v.push_back(val);
    			}else{
    				v.push_front(val);
    			}
    		}
    	}
    	for(auto c: v) {
    		cout<<c<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}