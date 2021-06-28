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
    	ll sum = 0;
    	vector<ll> v(n);
    	for(auto &c: v){
    		cin>>c;
    		sum+=c;
    	}

    	if(sum%n!=0){
    		cout<<"-1"<<endl;
    		continue;
    	}else{
    		ll count = 0;
    		ll avg = sum/n;
    		for(auto c: v){
    			if(c>avg){
    				count++;
    			}
    		}
    		cout<<count<<endl;
    	}
    }
    return 0;
}