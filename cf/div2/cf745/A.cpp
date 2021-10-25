#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1e9+7;

ll calculateFact(ll n) {
	ll value = 1;
	for(ll i=2;i<=n;i++) {
		value = i*value;
		value = value%mod;
	}
	return value;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	ll answer = calculateFact((2*n) -1);
    	cout<<(answer*n)%mod<<endl;
    }
    return 0;
}