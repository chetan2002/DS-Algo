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
    	for(auto &c: v) {
    		cin>>c;
    	}
    	sort(v.begin(), v.end());
    	vector<ll> val;
    	for(int i=1; i<n; i++) {
    		if(v[i]-v[i-1]!=0) {
    			val.push_back(abs(v[i]-v[i-1]));
    		}
    	}
    	if(val.size()==0) {
    		cout<<"-1"<<endl;
    		continue;
    	}
    	ll gcd = val[0];
    	for(auto c: val) {
    		if(c==0) {
    			continue;
    		}
    		gcd = __gcd(gcd, c);
    	}
    	cout<<gcd<<endl;
    }
    return 0;
}