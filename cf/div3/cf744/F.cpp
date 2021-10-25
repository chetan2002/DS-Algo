#include<bits/stdc++.h>
using namespace std;
#define ll long long int



void print(vector<ll> v) {
	for(auto c: v) {
		cout<<c<<" ";
	}
	cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , d;
    	cin>>n>>d;
    	vector<ll> v(n);
    	for(auto &c: v) {
    		cin>>c;
    	}
    	vector<vector<ll>> chains;
    	vector<ll> vis(n);
    	for(int i=0;i<n;i++) {
    		if(vis[i]==1) {
    			continue;
    		}
    		vis[i] = 1;
    		vector<ll> chain;
    		chain.push_back(v[i]);
    		int j = (i+d)%n;
    		while(vis[j]!=1) {
    			if(v[j] == 0) {
    				if(chain.back()!=0) {
    					chain.push_back(0);
    				}
    			}else{
    				if(chain.back()==0){
    					chain.push_back(1);
    				}else{
    					chain[chain.size()-1]++;;
    				}
    			}
    			vis[j] = 1;
    			j = (j+d)%n;
    		}
			chains.push_back(chain);	
    	}
    	ll maxi = 0;
    	bool possible = true;
    	for(auto c: chains) {
    		ll value = 0;
    		for(auto a: c) {
    			value = max(a,value);
    		}
    		value = max(value, c[0]+c.back());
    		if(c.size()==1 and c[0]!=0){
    			possible = false;
    			break;
    		}
    		maxi = max(value , maxi);
    	}
    	if(!possible) {
    		cout<<"-1"<<endl;
    	}else{
    		cout<<maxi<<endl;
    	}
    }
    return 0;
}