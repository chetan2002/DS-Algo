#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n ;cin>>n;

    	vector<ll> v;
    	for(int i=0;i<n;i++){
    		ll val;
    		cin>>val;
    		v.push_back(val);
    	}

    	vector<map<int,int>> prefix(n);
    	vector<map<int,int>> suffix(n);
    	prefix[0][v[0]]++;
    	for(int i=1;i<n;i++){
    		for(auto c: prefix[i-1]){
    			prefix[i][c.first] = c.second;
    		}
    		prefix[i][v[i]]++;
    	}

    	suffix[n-1][v[n-1]]++;
    	for(int i=n-2;i>=0;i--){
    		for(auto c: prefix[i+1]){
    			prefix[i][c.first] = c.second;
    		}
    		prefix[i][v[i]]++;
    	}
    	
    	
    	
    }
    return 0;
}