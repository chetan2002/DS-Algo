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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll  ans =0 ;
 	ll n ;
 	cin>>n;
 	vector<ll> v(n);
 	for(auto &i: v){
 		cin>>i;
 	}
 	sort(v.begin(),v.end());
 	int avg = 0;
 	if(n%2==1){
 		avg = v[n/2];
 	}else{
 		avg = (v[n/2] + v[(n+1)/2])/2;
 	}
 	for(auto c: v){
 		ans += (abs(c-avg));
 	}
 	cout<<ans<<endl;
    return 0;
}