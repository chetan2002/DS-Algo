#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool comp(pair<ll,ll> p1 , pair<ll,ll> p2){
	if(p1.first>p2.first){
		return true;
	}else
	if(p1.first==p2.first){
		if(p1.second<p2.second){
			return true;
		}
	}
	return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , k;
 	cin>>n>>k;
 	vector<pair<ll,ll>> vp;
 	for(int i=0;i<n;i++){
 		ll a , b;cin>>a>>b;
 		vp.push_back({a,b});
 	}
 	sort(vp.begin(),vp.end(),comp);

 	map<pair<ll,ll>,int> mp;
 	for(auto c: vp){
 		mp[c]++;
 	}
 	cout<<mp[vp[k-1]]<<endl;
    return 0;
}