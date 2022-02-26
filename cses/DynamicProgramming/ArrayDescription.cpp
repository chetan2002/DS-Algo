#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v;
const ll MOD = 1e9 + 7;

ll answer(ll n, ll k) {
	vector<vector<ll>> mp(n, vector<ll>(k+1, 0));
	if(v[0]==0) {
		for(int i=1; i<=k; i++) {
			mp[0][i] = 1;
		}		
	}else {
		mp[0][v[0]] = 1;
	}
	for(int i=1; i<n; i++) {
		if(v[i]!=0) {
			mp[i][v[i]] = (mp[i-1][v[i]])%MOD;
			if(v[i]-1>=1) {
				mp[i][v[i]] += (mp[i-1][v[i]-1]%MOD);
			}
			if(v[i]+1<=k) {
				mp[i][v[i]] += (mp[i-1][v[i]+1]%MOD);
			}
			mp[i][v[i]]%=MOD;
		}else {
			for(int j=1; j<=k; j++) {
				pair<ll, ll> c = {j, mp[i-1][j]};
				if(c.first + 1 <=k) {
					mp[i][c.first+1] += c.second;
					mp[i][c.first+1] %= MOD;
				}
				if(c.first -1 >=1) {
					mp[i][c.first-1] += c.second;
					mp[i][c.first-1] %= MOD;
				}
				mp[i][c.first] += c.second;
				mp[i][c.first] %= MOD;	
			}
		}
	}
	ll sum =0;
	for(auto c: mp[n-1]) {
		sum+= c;
		sum %= MOD;
		// cout<<c<<" ";
	}
	return sum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, k;
 	cin>>n>>k;

 	v.resize(n);
 	for(auto &c: v) {
 		cin>>c;
 	}   
 	cout<<answer(n, k)<<endl;
    return 0;
}