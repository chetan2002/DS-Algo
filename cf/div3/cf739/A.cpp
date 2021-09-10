#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
	ll count = 0;
    vector<ll> v;
    while(t--){
    	ll n;cin>>n;
    	if(v.size()>n){
    		cout<<v[n-1]<<endl;
    	}else{
    		while(v.size()<n){
    			if(count%10!=3 and count%3!=0){
    				v.push_back(count);
    			}
				count++;	
    		}

    		cout<<v[n-1]<<endl;
    	}
    }
    return 0;
}