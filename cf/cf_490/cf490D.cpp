#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , m;
 	cin>>n>>m;
 	vector<ll> v(n);
 	for(ll i =0;i<n ; i++){
 		cin>>v[i];
 	}

 	vector<ll> mp(m,0);
 	for(auto c: v){
 		mp[c%m]++;
 	}
 	ll count =0;
 	ll r = n/m;
 	for(auto c: mp){
 		if(c<(n/m)){
 			count++;
 		}
 	}
 	cout<<count<<endl;
    return 0;
}