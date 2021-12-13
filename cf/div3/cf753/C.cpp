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
    	for(auto &c: v){ 
    		cin>>c;
    	}
    	priority_queue<ll, vector<ll>, greater<ll>> pq;
    	for(auto c: v) {
    		pq.push(c);
    	}
    	ll mini = LLONG_MIN;
    	ll sub = 0;
    	while(!pq.empty()) {
    		ll top = pq.top();
    		pq.pop();
    		mini = max(mini, top-sub);
    		sub = sub+(top-sub);
    		// cout<<top<<" "<<sub<<endl;;
    	}
   		// cout<<endl;
    	cout<<mini<<endl;
    }
    return 0;
}