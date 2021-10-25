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
    	priority_queue<pair<ll,ll>> pq;;
    	for(int i=0;i<n;i++) {
    		if(v[i]<=0) {
    			continue;
    		}
    		pq.push({v[i],i+1});
    	}
    	vector<pair<ll,ll>> vp;
    	while(pq.size()>1) {
    		auto a = pq.top();
    		pq.pop();
    		auto b = pq.top();

    		pq.pop();
    		vp.push_back({a.second, b.second});
    		a.first = a.first -1;;
    		b.first = b.first -1;
    		if(a.first>0) {
    			pq.push(a);
    		}
    		if(b.first>0) {
    			pq.push(b);
    		}
    	}
    	cout<<vp.size()<<endl;
    	for(auto c: vp) {
    		cout<<c.first<<" "<<c.second<<endl;
    	}
    }

    return 0;
}