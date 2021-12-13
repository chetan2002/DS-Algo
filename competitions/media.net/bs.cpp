#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool tryMid(vector<vector<ll>> &a, ll b, ll c, ll x) {
	double tt = 0.0;
	int prev = 0;
	for(int i=0;i<a.size();i++) {
		int bettp = a[i][0];
		tt+=(bettp - prev)/(x*1.0);
		x+=a[i][1];
		prev=bettp;
	}
	tt+=(b - prev)/(x*1.0);
	return tt<=c;
}

ll answer(vector<vector<ll>> A, ll B, ll C) {
	sort(A.begin(), A.end());
	ll s = 1, e = B;
	ll ans = B; 
	while(s<=e) {
		ll mid = s + (e-s)/2;
		if(tryMid(A, B, C, mid)) {
			ans = mid;
			e = mid -1 ;
		}else{
			s = mid+1;
		}
	}
	return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	vector<vector<ll>> vp;
    	for(int i=0; i<n; i++) {
    		int a, b;
    		cin>>a>>b;
    		vp.push_back({a,b});
    	}
    	ll b, c;
    	cin>>b>>c;

    	cout<<answer(vp, b, c)<<endl;

    }
    return 0;
}