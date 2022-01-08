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
 	
 	ll n;
 	cin>>n;
 	ll k; cin>>k; 
 	vector<ll> v(n);
 	for(auto &c: v) {
 		cin>>c;
 	}   

 	unordered_map<ll, ll, custom_hash> mp;
 	int s =0, e = 0;
 	ll count =0;
 	while(e<n) {
 		mp[v[e]]++;
 		if(mp.size()>k) {
 			while(mp.size()>k) {
 				mp[v[s]]--;
 				if(mp[v[s]] == 0) {
 					mp.erase(v[s]);
 				}
 				s++;
 			}
 		}
 		count+=(e-s+1);
 		e++;
 	}
 	cout<<count<<endl;
    return 0;
}