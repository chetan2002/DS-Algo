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
 	
 	ll n ;
 	cin>>n;
 	ll arr[n];
 	ll prefix[n+1]={0};
 	for(int i=0;i<n;i++){
 		cin>>arr[i];
 		prefix[i+1] = prefix[i]+arr[i];
 	}
 	ll ans =0;
 	unordered_set<ll , custom_hash> s;
 	s.insert(0);
 	ll begin = 0 , end = 0;
 	while(begin<n){
 		while(end<n and !s.count(prefix[end+1])){
 			end++;
 			s.insert(prefix[end]);
 		}
 		ans += end-begin;
 		s.erase(prefix[begin]);
 		begin++;
 	}
 	cout<<ans<<endl;
    return 0;
}