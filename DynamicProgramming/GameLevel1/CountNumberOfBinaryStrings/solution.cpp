#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//You are provided an integers N. 
//You need to count all possible distinct binary strings of length N 
//such that there are no consecutive 1’s.


vector<vector<ll>> memo;

ll topDown(ll n , ll num){
	if(n==1){
		return memo[n][num]=1;
	}
	if(memo[n][num]!=0){
		return memo[n][num];
	}
	ll zer = 0;
	zer = topDown(n-1,0);
	if(num==0){
		zer+= topDown(n-1 ,1);
	}
	return memo[n][num]=zer;
}

ll bottomUp(ll n){
	vector<vector<ll>> dp(n+1,vector<ll>(2,0));
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int i=2;i<=n;i++){
		dp[i][0]= dp[i-1][0]+dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	return dp[n][0]+dp[n][1];
}
ll bottomUpMemoryOptimised(ll n){
	ll zero = 1 , one = 1;
	for(int i=2;i<=n;i++){
		swap(zero,one);
		zero+=one;
	}
	return zero+one;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;cin>>n;
    memo.resize(n+1 , vector<ll>(2,0));
    cout<<topDown(n,0)+topDown(n,1)<<endl;
    cout<<bottomUp(n)<<endl;
    cout<<bottomUpMemoryOptimised(n)<<endl;
    return 0;
}