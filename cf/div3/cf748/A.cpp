#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll a, b , c;
    	int maxi = 0;
    	cin>>a>>b>>c;
    	unordered_map<ll,int> mp;
    	maxi = max(a, max(b,c));
    	mp[a]++;
    	mp[b]++;
    	mp[c]++;

    	if(a == maxi) {
    		if(mp[maxi]==1) {
    			cout<<0<<" ";
    		}else{
    			cout<<1<<" ";
    		}
    	}else{
    		cout<<maxi+1-a<<" ";
    	}

    	if(b == maxi) {
    		if(mp[maxi]==1) {
    			cout<<0<<" ";
    		}else{
    			cout<<1<<" ";
    		}
    	}else{
    		cout<<maxi+1-b<<" ";
    	}

    	if(c == maxi) {
    		if(mp[maxi]==1) {
    			cout<<0<<endl;
    		}else{
    			cout<<1<<endl;
    		}
    	}else{
    		cout<<maxi+1-c<<endl;
    	}
    }
    return 0;
}