#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n, k;cin>>n>>k;
    	vector<ll> v(k);
    	for(auto &c: v){ 
    		cin>>c;
    		c = n-c;
    	}
    	sort(v.begin(), v.end(), greater<ll>());
    	reverse(v.begin(), v.end());
    	ll count =0 ;
    	for(auto c: v) {
    		if(c==0) {
    			count++;
    			continue;
    		}
    		n-=c;
    		if(n<=0){ 
    			break;
    		}
    		count++;
    	}
    	cout<<count<<endl;
    }
    return 0;
}