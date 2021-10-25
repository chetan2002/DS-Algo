#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , k;cin>>n>>k;
    	vector<ll> v(k);
    	for(auto &c: v) {
    		cin>>c;
    	}

    	int count =0 ;
    	for(int i=0; i<k; i++) {
    		for(int j=0; j<i; j++) {
    			if(v[j] < v[i]) {
    				count++;
    			}
    		}
    	}
    	cout<<count<<endl;

    }
    return 0;
}