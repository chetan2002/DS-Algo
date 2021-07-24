//do again

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v;
vector<vector<ll>> memo;


ll topDown(ll n , ll sum){
	if(n==0){
		return 0;
	}
	// if(sum<0){
	// 	return 0;
	// }
	if(sum==0){
		return memo[sum][n-1]=1;
	}
	if(memo[sum][n-1]!=-1){
		return memo[sum][n-1];
	}
	ll ans1 = 0 ;
	if(sum>=v[n-1]){
		ans1= topDown(n , sum-v[n-1]);
	}
	ans1 += topDown(n-1,sum);
	
	return memo[sum][n-1] = ans1;

}
ll bottomUp(ll n , ll sum){
	vector<vector<ll>> dp(sum+1,vector<ll>(n+1,0));
	for(int j=0;j<=n;j++){
		dp[0][j]=1;
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++){
			if(i-v[j-1]>=0){
				dp[i][j] = dp[i][j-1]+dp[i-v[j-1]][j];
			}else{
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	// for(auto c: dp){
	// 	cout<<c<<" ";
	// }
	return dp[sum][n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n , sum;
 	cin>>n>>sum;   
 	v.resize(n);
 	for(auto &i: v){
 		cin>>i;
 	}
 	sort(v.begin(),v.end());
 	memo.resize(sum+1,vector<ll>(n,-1));
 	cout<<topDown(n , sum)<<endl;
 	cout<<bottomUp(n,sum)<<endl;
    return 0;
}