#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll xorW(ll n , vector<ll> v){
	ll xo =0 ;


	for(int i=1;i<=n;i++){       // 1-n ->   = xor
		xo = xo^i;
	}



	for(auto c: v){

		xo = xo^c;				// 1^2^3^4^4^2^3 = 1
	}


	return xo;
}

ll ImMap(ll n , vector<ll> v){

	// 1 -> 1
	// 2 -> 0
	// 3 -> 0
	// 4 -> 0

	// declare map
	unordered_map<ll,ll> mp;

	// map k andar 1 - n values daali
	for(int i=1;i<=n;i++){
		mp[i]=1;
	}

	// ab jo number vector me the , wo minus krdiye
	for(auto c: v){
		mp[c]--;
	}

	for(auto c: mp){
		if(c.second==1){
			return c.first;
		}
	}
	return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;
 	cin>>n;

 	vector<ll> v(n);
 	for(int i=0;i<n-1;i++){
 		cin>>v[i];
 	}

 	cout<<ImMap(n , v)<<endl;
 	cout<<xorW(n , v)<<endl;

    return 0;
}