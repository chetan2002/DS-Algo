#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll answer(ll n){
	if(n==1){
		return 1;
	}
	if(n==2){
		return 2;
	}
	vector<ll> v;
	ll prev = 1;
	ll sum = 3;
	ll val = 0;
	for(ll i=2;i<n;i++){
		val = (sum+i+1)%998244353;
		sum = (sum+val)%998244353;
	}

	return val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin>>n;
	cout<<answer(n)<<endl;
    return 0;
}