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
    	for(auto &i: v){
    		cin>>i;
    	}
    	ll count = 0;
    	for(int i=1;i<=n;i++){
    		ll value = v[i-1];
    		for(int j=1;value<=2*n;j++){
                value = v[i-1]*j - i;
    			if(value<=i){
    				continue;
    			}
                if(value>n){
                    continue;
                }

    			if(v[value-1]*v[i-1]==value+i){
    				count++;
    			}
    		}
    	}
        cout<<count<<endl;
    }
    return 0;
}