#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

set<ll> powertwo;

ll answer(ll n , ll x){
	if(n==0){
		return 0;
	}
	if(x==0 and n%2==1){
		return -1;
	}
	if(x>=n){
		return 1;
	}
	if(powertwo.find(n)!=powertwo.end()){
		return 1;
	}
	auto it = powertwo.lower_bound(n);
	it--;
	return 1+ answer(n-(*it) , x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    ll value = 2;
    for(ll i=0;i<=30;i++){
    	powertwo.insert(value);
    	value = value*4;
    }
    while(t--){
    	ll n , x;
    	cin>>n>>x;

    	cout<<answer(n, x)<<endl;

    }
    return 0;
}