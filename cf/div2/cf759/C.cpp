#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll solve(vector<ll> v, ll k) {
	if(v.size()==0) {
		return 0;
	}
	ll total =0;
	while(!v.empty()) {
		if(total==0){ 
			total = v.back();
		}else{
			total += 2*v.back();
		}
		for(int i=0; i<k; i++) {
			if(v.size()==0) {
				break;
			}
			v.pop_back();
		}
	}
	return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n, k;cin>>n>>k;
    	vector<ll> negative;
    	vector<ll> positive;

    	for(ll i=0; i<n; i++) {
    		ll val;cin>>val;
    		if(val<0) {
    			negative.push_back(abs(val));
    		}else
    		if(val>0){
    			positive.push_back(val);
    		}
    	}
    	sort(negative.begin(), negative.end());
    	sort(positive.begin(), positive.end());

    	ll value2 = solve(negative, k);
    	ll value1 = solve(positive, k);
    	if(negative.size()==0) {
    		cout<<value1<<endl;
    	}else
    	if(positive.size()==0) {
    		cout<<value2<<endl;
    	}else{
    		cout<<value1 + value2 + min(positive.back(), negative.back())<<endl;
    	}
    }
    return 0;
}