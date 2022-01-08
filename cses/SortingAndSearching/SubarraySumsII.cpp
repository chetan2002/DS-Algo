#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 	ll n, k;
 	cin>>n>>k;

 	vector<ll> v(n);
 	map<ll,ll> mp;

 	ll sum = 0;
 	ll count =0;

	mp[0]= 1;

 	for(auto &c: v) {
 		cin>>c;
 		sum+=c;
 		if(mp.find(sum-k)!=mp.end()) {
 			count+=mp[sum-k];
 		}
 		mp[sum]++;
 	}

 	cout<<count<<endl;
    return 0;
}