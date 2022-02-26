 #include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v;
vector<vector<pair<ll,ll>>> dp;
pair<ll,ll> answer(int i, int j) {
	if(i==j) {
		return {v[i],0};
	}
	if(dp[i][j].first!=0 or dp[i][j].second!=0) {
		return dp[i][j];
	}
 	pair<ll,ll> f = answer(i+1, j);
 	pair<ll, ll> s = answer(i, j-1);
 	pair<ll,ll> p =  {max(v[i] +f.second, v[j]+s.second), min(f.first, s.first)};
 	return dp[i][j]=p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n; 
 	cin>>n; 
 	v.resize(n); 
 	for(auto &c: v) {
 		cin>>c; 
 	}
 	dp.resize(n, vector<pair<ll,ll>>(n, {0, 0}));
 	cout<<answer(0, n-1).first<<endl;
    return 0;
}