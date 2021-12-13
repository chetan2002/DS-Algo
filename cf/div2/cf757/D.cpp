#include<bits/stdc++.h>
using namespace std;
#define ll long long int

unordered_map<ll, ll> mp;
bool comp(ll a, ll b) {
	if(a==b) {
		return true;
	}
	return a%b>0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	vector<ll> v(n);
 	for(auto &c: v) {
 		cin>>c;
 	}
 	sort(v.begin(), v.end(), greater<ll>());
 	// for(auto c: mp) {
 	// 	mp[c]++;
 	// }
 	sort(v.begin(), v.end(), comp);
 	reverse(v.begin(), v.end());
 	ll ans =0, zor =v[0];
 	for(auto c: v) {
 		cout<<c<<" ";
 		zor = __gcd(c, zor);
 		ans += zor;
 	}
 	cout<<endl;
 	cout<<ans<<endl;
    return 0;
}