#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//Given n friends, each one can remain single or can be paired up with some other friend. 
//Each friend can be paired only once. 
//Find out the total number of ways in which friends can remain single or can be paired up.
vector<ll> memo;

ll topDown(ll n){
	if(n<=2){
		return memo[n]=n;

	}

	ll single = 0 , pair = 0;
	single = topDown(n-1);
	pair = (n-1)*topDown(n-2);
	return memo[n]=single+pair;
}

ll bottomUp(ll n){
	vector<ll> dp(n+1,0);
	dp[1]=1;
	dp[2] = 2;
	for(int i=3;i<=n;i++){
		dp[i] = dp[i-1]+ (i-1)*dp[i-2];
	}
	return dp[n];;
}


ll bottomUpSpaceOptimised(ll n){
	if(n<=2){
		return n; 
	}
	ll twoBack = 1;
	ll OneBack =2;
	for(int i=3;i<=n;i++){
		twoBack = OneBack + (i-1)*twoBack;
		swap(twoBack,OneBack);
	}
	return OneBack;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;cin>>n;
 	memo.resize(n+1,0);
 	cout<<topDown(n)<<endl;
 	cout<<bottomUp(n)<<endl;
 	cout<<bottomUpSpaceOptimised(n)<<endl;
    return 0;
}