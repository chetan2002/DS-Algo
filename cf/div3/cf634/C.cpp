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
    	for(int i=0;i<n;i++){
    		cin>>v[i];
    	}

    	unordered_map<ll , ll> mp;
    	for(auto c: v){
    		mp[c]++;
    	}

    	int maxi = 0 , maxEl = v[0];
    	for(auto c: mp){
    		if(c.second>maxi){
    			maxi = c.second;
    			maxEl = c.first;
    		}
    	}

    	int size1 = mp.size()-1;
    	int size2 = maxi;

    	if(size1>=size2){
    		cout<<size2<<endl;
    	}else{
    		if(size2-size1 == 1){
    			cout<<size1<<endl;
    		}else{
    			cout<<size1+1<<endl;
    		}
    	}

    }
    return 0;
}