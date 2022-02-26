#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(ll a, ll b, ll c, ll k) {
	if(a*1 + b*2 + c*3 == k) {
		return true;
	}
	if(a*1 + b*2 + c*3 <k ) {
		return false;
	}
	if(a>=k) {
		return true;
	}
	if(2*b>=k) {
		if(a==0 and c==0) {
			return k%2==0;
		}else 
		return true;
	}
	if(3*c >=k) {
		if(a>=1 and b>=1) {
			return true;
		}else
		if(a>1) {
			return true;
		}else
		if(b>1) {
			return true;
		}else {
			return k%3==0;
		}
	}else {
		bool ans = false;
		if(c!=0) {
			ans = ans or check(a, b, 0, k-3*c);
		}
		if(c>=1) {
			ans = ans or check(a, b, 1, k - 3*(c-1)); 
		}
		if(c>=2) {
			ans = ans or check(a, b, 2, k-3*(c-2));
		}
		return ans;
	}
}

ll answer(ll a, ll b, ll c, vector<ll> &v) {
	int count =0;
	for(auto k: v) {
		if(check(a, b, c, k)) {
			count++;
		}
	}
	return count;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	ll a, b, c;
 	cin>>a>>b>>c; 
 	vector<ll> v(n);
 	for(auto &c: v) {
 		cin>>c;
 	}  
 	cout<<answer(a, b, c, v)<<endl;
    return 0;
}