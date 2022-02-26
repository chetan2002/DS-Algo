#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, k; 
string s;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	cin>>n>>k; 
    	cin>>s;
    	vector<ll> freq(26, 0);
    	for(auto c: s) {
    		freq[c-'a']++;
    	}
    	ll value = 0;
    	for(auto &c: freq) {
    		value+=(c/2);
    	}
    	// cout<<value<<" ";
    	ll rem = (value%k)*2 + (n-2*value);
    	ll ans = (value/k)*2 + (rem>=k?1:0);
    	cout<<ans<<endl;
    }
    return 0;
}