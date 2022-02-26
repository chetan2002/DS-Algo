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
    	set<ll> s;
    	bool ans = true;
    	for(auto &c: v) {
    		while(c>n) {
    			c/=2;
    		}
    		while(s.find(c)!=s.end()) {
    			c/=2;
    		}
    		if(c!=0) {
    			s.insert(c);
    		}
    	}
    	if(s.size()==n) {
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}