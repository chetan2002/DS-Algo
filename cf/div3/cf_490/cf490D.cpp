#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , m;
 	cin>>n>>m;
 	ll k=(n/m);
 	vector<ll> v(n);
 	vector<vector<ll>> divide(m);
 	for(ll i =0;i<n ; i++){
 		cin>>v[i];
 		divide[v[i]%m].push_back(i);
 	}
 	
 	ll ans = 0;
 	vector<pair<ll,ll>> fre;
 	for(int i=0;i<2*m;i++){
 		int cur = i%m;
 		while(divide[cur].size()>k){
 			int ele = divide[cur].back();
 			divide[cur].pop_back();
 			fre.push_back(make_pair(ele,i));
 		}
 		while(divide[cur].size()<k and !fre.empty()){
 			int elem = fre.back().first;
 			int mmod = fre.back().second;
 			fre.pop_back();
 			divide[cur].push_back(elem);
 			v[elem] += i - mmod;
 			ans += i-mmod;
 		}
 	}
 	cout<<ans<<endl;
 	for(auto c: v){
 		cout<<c<<" ";
 	}
    return 0;
}