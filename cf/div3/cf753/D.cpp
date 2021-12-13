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
    	for(auto &c: v) {
    		cin>>c;
    	}
    	string s;
    	cin>>s;
    	multiset<ll> B;
    	multiset<ll> R;
    	bool ans = true;
    	for(int i=0; i<n; i++) {
    		if(s[i]=='R') {
    			R.insert(v[i]);
    			if (v[i]>n) {
    				ans = false;
    				break;
    			}
    		}else{
    			B.insert(v[i]);
    			if(v[i]<1) {
    				ans = false;
    				break;
    			}
    		}
    	}

    	if(!ans) {
    		cout<<"NO"<<endl;
    		continue;
    	}
    	for(int i=1; i<=n; i++) {
    		if(!B.empty()) {
    			auto c = *(B.begin());
    			B.erase(B.begin());
    			if(c<i) {
    				ans = false;
    				break;
    			}
    		}else {
    			auto c = *(R.begin());
    			R.erase(R.begin());
    			if(c>i) {
    				ans = false;
    				break;
    			}
    		}
    	}
    	if(ans) {
    		cout<<"YES"<<endl;
    	}else{ 
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}