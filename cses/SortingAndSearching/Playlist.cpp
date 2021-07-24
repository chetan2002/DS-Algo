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
 	ll n;cin>>n;
 	vector<ll> v(n);
 	for(auto &i: v){
 		cin>>i;
 	}   

 	int i=0 , j=0 ,maxi=1;
 	unordered_set<ll,custom_hash> mp;
 	while(j<n){
 		if(mp.find(v[j])!=mp.end()){
 			mp.erase(v[i]);
 			i++;
 		}else{
 			mp.insert(v[j]);
 			j++;
 		}
 		maxi = max(maxi , j-i);
 	}
 	cout<<maxi<<endl;
    return 0;
}