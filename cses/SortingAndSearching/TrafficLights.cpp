#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll l, n; cin>>l>>n;
 	multiset<ll> dis;
 	dis.insert(l);
 	set<ll> pos;
 	pos.insert(0);
 	pos.insert(l);

 	for(int i=0;i<n;i++){
 		ll p;cin>>p;
 		if(pos.find(p)==pos.end()){
	 		auto ub= pos.upper_bound(p);
	 		auto lb = ub;--lb;
	 		int distanceOld = *ub-*lb;
	 		auto dist = dis.find(distanceOld);
	 		dis.erase(dist);
	 		ll d1 = p-(*lb);
	 		ll d2 = (*ub) - p;
	 		pos.insert(p);
	 		dis.insert(d1);
	 		dis.insert(d2);
 		}
 		auto it = dis.end();
		it--;
		cout<<(*it)<<" ";
 	}
    return 0;
}