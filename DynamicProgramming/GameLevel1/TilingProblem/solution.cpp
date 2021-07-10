#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> memo;
//given brick wall of m*n and tiles of size 1*m
//find no. of ways to arrange tiles on wall
ll topDown(ll n,ll m){
	if(n==0 || m==0){
		return 0;
	}
	if(n<m){
		return 1;
	}
	if(n==m){
		return 2;
	}
	if(memo[n][m]!=-1){
		return memo[n][m];
	}
	ll hor =topDown(n-1 , m);
	ll ver = 0;
	if(n>m){
		ver =topDown(n-m , m);
	}
	return memo[n][m] = hor+ver;
}

ll bottomUp(ll n , ll m){
	vector<vector<ll>> dp(n+1 , vector<ll>(m,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i<j){
				dp[i][j] = 1;
			}else
			if(i==j){
				dp[i][j] = 2;
			}else{
				dp[i][j] = dp[i-1][j] + dp[i-j][j];
			}
		}
	}
	return dp[n][m];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    memo.resize(n+1,vector<ll>(m+1,-1));
    cout<<topDown(n,m)<<endl;
    cout<<bottomUp(n,m)<<endl;
    return 0;
}