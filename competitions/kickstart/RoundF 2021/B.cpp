#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(int l=1;l<=t;l++){
    	ll d , n , k;
    	cin>>d>>n>>k;
    	vector<vector<ll>> vp(d+1);
    	for(int i=0;i<n;i++){
    		ll h, s, e;
    		cin>>h>>s>>e;
    		vp[s].push_back(h);
    		vp[e].push_back(-h);
    	}
    	ll count = 0;
    	multiset<ll> pq;
    	multiset<ll, greater<ll>> s;
    	ll sum =0;
    	for(int i=1;i<=d;i++){
    		for(auto c: vp[i]) {
    			if(c>=0){
    				if(pq.size()<k) {
    					sum+=c;
    					pq.insert(c);
    				}else {
    					s.insert(c);
    					if(*s.begin()>*pq.begin()){
    						int value = *s.begin();
    						int vald = *pq.begin();
    						s.erase(s.begin());
    						pq.erase(pq.begin());
    						s.insert(vald);
    						pq.insert(value);
    						sum += value - vald;
    					}
    				}
    			}
    		}
    		// int a = 0;
    		// ll sum =0 ;
    		// for(auto c: s) {
    		// 	if(a==k) {
    		// 		break;
    		// 	}
    		// 	sum += c;
    		// 	a++;
    		// }
    		count = max(count , sum);
    		for(auto c: vp[i]) {
    			if(c<0){
    				int el = -c;
    				if(el>=*pq.begin()) {
    					sum -= el;
    					pq.erase(pq.find(el));
    					if(!s.empty()) {
    						int value = *s.begin();
    						sum+= value;
    						s.erase(s.begin());
    						pq.insert(value);
    					}
    				}else {
    					s.erase(s.find(el));
    				}
    			}
    		}

    	}
    	cout<<"Case #"<<l<<": "<<count<<endl;
    }
    return 0;
}