#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
vector<ll> v;

bool check(ll k, ll mid) {
	ll count = 0;
	for(auto c: v) {
		count += (mid/c);
	}
	return count>=k;
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
 	ll s=0, e = ULLONG_MAX;
 	ll ans = e;
 	while(s<=e) {
 		ll mid = s + (e-s)/2;
 		if(check(k, mid)) {
 			ans = min(mid, ans);
 			e = mid-1;
 		}else {
 			s = mid+1;
 		}
 	}
 	cout<<ans<<endl;
    return 0;
}