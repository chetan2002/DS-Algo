//https://hack.codingblocks.com/app/contests/2022/1101/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll mod = 1000000007;
ll answer(string s){
	vector<ll> occ(26 , -1);
	ll dp[s.length()+1];
	dp[0]=1;
	for(int i=1;i<=s.length() ;i++){
		dp[i] = (dp[i-1]*2)%mod;

		if(occ[(int)(s[i-1]-'A')]!=-1){
			dp[i] = (dp[i] - dp[occ[(int)(s[i-1]-'A')]] + mod)%mod;
		}
		dp[i] = dp[i]%mod;
		occ[(int)(s[i-1]-'A')] = i-1;
	}
	return dp[s.length()]%mod;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<answer(s)<<endl;
	}
	return 0;
}