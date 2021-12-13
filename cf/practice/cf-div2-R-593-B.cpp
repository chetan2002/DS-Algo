#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll>> ans(ll n) {
	vector<vector<ll>> v(n);
	ll a = 1;
	while(a<=n*n) {
		for(int i=0; i<n; i++) {
			v[i].push_back(a++);
		}
		if(a<=n*n) {
			for(int i=n-1; i>=0; i--) {
				v[i].push_back(a++);
			}
		}
	}
	return v;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n; cin>>n;
 	vector<vector<ll>> v = ans(n);
 	for(auto c: v) {
 		for(auto a: c) {
 			cout<<a<<" ";
 		}
 		cout<<endl;
 	}

    return 0;
}