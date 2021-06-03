#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	vector<vector<ll>> v(n);
 	vector<ll> sumV(n);
 	for(int i=0;i<n;i++){
 		ll k;
 		cin>>k;
 		for(ll j=0;j<k;j++){
 			ll val;
 			cin>>val;
 			v[i].push_back(val);
 			sumV[i]+=val;
 		}
 	}
 	bool printed = false;
 	unordered_map<ll,pair<ll,ll>> mp;
 	for(ll i=0;i<n;i++){
 		for(ll j=0;j<v[i].size();j++){
 			ll val = sumV[i]-v[i][j];
 			if(mp.find(val)!=mp.end()){
 				if(mp[val].first == i+1){
 					continue;;
 				}
 				printed = true;
 				cout<<"YES"<<endl;
 				cout<<mp[val].first<<" "<<mp[val].second<<endl;
 				cout<<i+1<<" "<<j+1<<endl;
 				break;
 			}else{
 				mp.insert({val , {i+1 , j+1}});
 			}
 		}
 		if(printed){
 			break;
 		}
 	}
 	if(!printed){
 		cout<<"NO"<<endl;
 	}
    return 0;
}