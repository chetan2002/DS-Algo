#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n, l , r, k;
    	cin>>n>>l>>r>>k;
    	vector<ll> v(n);
    	for(int i=0; i<n; i++) {
    		cin>>v[i];
    	}
    	sort(v.begin(), v.end());

    	ll count =0 ;
    	for(auto c: v) {
    		if(c>=l and c<=r) {
    			if(k>=c) {
    				k-=c;
    				count++;
    			}
    		}
    	}
    	cout<<count<<endl;
    }
    return 0;
}