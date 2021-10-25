#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool comp(pair<ll,ll> p1, pair<ll,ll> p2) {
	if(p1.first < p2.first) {
		return true;
	}
	if(p1.first > p2.first) {
		return false;
	}
	return p1.second>p2.second;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , m;
    	cin>>n>>m;
    	vector<pair<ll,ll>> vp;
    	for(int i=1;i<=n*m;i++) {
    		ll val;
    		cin>>val;
    		vp.push_back({val, i});
    	}
    	sort(vp.begin(),vp.end());
    	for(int i=0;i<n;i++){
	    	sort(vp.begin()+(i*m), vp.begin()+(i+1)*m, comp);	
    	}
		ll count =0;
        set<int> s;
        
        // for(auto c: vp) {
        // 	cout<<c.first<<" "<<c.second<<endl;
        // }

        for(int j=0; j<vp.size(); j++) {
            if(j%m==0) {
                s.clear();
            }
            s.insert(vp[j].second);
            auto it = s.lower_bound(vp[j].second);
            int dis = distance(s.begin(), it);
            count+=dis;
        }
    	cout<<count<<endl;
    }
    return 0;
}