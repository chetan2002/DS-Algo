#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> dp;
vector<string> mat;
ll n, m;
struct pair_hash {
    inline std::size_t operator()(const std::pair<ll,ll> & v) const {
        return v.first*31+v.second;
    }
};
unordered_set<pair<ll,ll>, pair_hash> mp;
ll dfs(ll i, ll j) {
	if(i>=n || j>=m || i<0 || j<0) {
		return 0;
	}
	if(dp[i][j]!=-1) {
		return dp[i][j];
	}
	if (mp.find({i,j})!=mp.end()) {
		dp[i][j] = -1;
		return 0;
	}
	char c = mat[i][j];
	mp.insert({i,j});
	// cout<<c<<" "<<i<<" "<<j<<endl;
	ll answer =0;
	if(c=='U') {
		answer = dfs(i-1, j);
	}else
	if(c=='D') {
		answer = dfs(i+1, j);
	}else
	if(c=='L'){
		answer = dfs(i, j-1);
	}else
	if(c=='R'){
		answer = dfs(i, j+1);
	}
	// mp.erase({i,j});
	if (mp.find({i,j})!=mp.end()) {
		return answer+1;
	}
	return dp[i][j] = answer + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	dp.clear();
    	dp.resize(n, vector<ll>(m,-1));
    	mat.clear();
    	mp.clear();
    	for(int i=0; i<n; i++) {
    		string s;
    		cin>>s;
    		mat.push_back(s);
    	}
    	// cout<<"working1"<<endl;
    	ll maxi = 0;
    	for(ll i=0; i<n; i++) {
    		for(ll j=0; j<m; j++) {
    			if(dp[i][j]==-1) {
    				mp.clear();
    				dp[i][j] = dfs(i,j);
    				maxi = max(maxi, dp[i][j]);
    			}
    		}
    	}
    	// if(maxi >= )
    	// cout<<"working2"<<endl;
    	ll x=-1, y=-1;
    	for(ll i=0; i<n; i++) {
    		for(ll j=0; j<m; j++) {
    			if(dp[i][j]==maxi) {
    				x = i;
    				y = j; 
    				break;
    			}
    		}
    		if (x!=-1 and y!=-1) {
    			break;
    		}
    	}
    	// for(auto c: dp) {
    	// 	for(auto a: c){ 
    	// 		cout<<a<<" ";
    	// 	}
    	// }
    	cout<<x+1<<" "<<y+1<<" "<<maxi<<endl;
    }
    return 0;
}