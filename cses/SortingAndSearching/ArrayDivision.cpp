#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool possible(vector<ll> &v, ll k, ll mid) {
	ll sum =0;
	for(auto c: v) {
		if(sum+c>mid) {
			k--;
			if(k==0) {
				return false;
			}
			sum=c;
		}else {
			sum+=c;
		}
		if(mid<c) {
			return false;
		}
	}
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, k;
 	cin>>n>>k;

 	vector<ll> v(n);
 	ll sum = 0;
 	for(auto &c: v) {
 		cin>>c;
 		sum+=c;
 	}   
 	ll s = 0, e = sum;
 	ll ans =e;
 	while(s<=e) {
 		ll mid = s + (e-s)/2;
 		if(possible(v, k, mid)) {
 			ans = mid;
 			e = mid-1;
 		}else{
 			s = mid+1;
 		}
 	}
 	cout<<ans<<endl;
    return 0;
}