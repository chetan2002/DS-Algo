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
    	unordered_set<ll> s;
    	for(ll i=1; i<=sqrt(n); i++) {
    		ll a = i*i;
    		ll b = i*i*i;
    		if(a<=n) {
    			s.insert(a);
    		}
    		if(b<=n) {
    			s.insert(b);
    		}
    	}
    	cout<<s.size()<<endl;
    }
    return 0;
}