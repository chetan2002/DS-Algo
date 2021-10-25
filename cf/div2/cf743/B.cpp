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
    	vector<ll> v1(n);
    	for(auto &c: v1){
    		cin>>c;
    	}
    	vector<ll> v2(n);
    	for(auto &c: v2){
    		cin>>c;
    	}
    	int countMin =n ;
    	if(v1[0]<v2[0]){
    		cout<<0<<endl;
    		continue;
    	}
    	
    }
    return 0;
}