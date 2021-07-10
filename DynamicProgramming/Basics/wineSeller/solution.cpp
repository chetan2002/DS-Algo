#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> memo;
// in 1 year you have to sell 1 bottle from extreme ends
//and in yth year the the price of ith bottle will be y*bottle[i];
//find max profit 

ll topDown(vector<ll> v , ll i , ll j , ll count){
	if(i>j){
		return 0;
	}
	ll &ans = memo[i][j];
	if(ans != -1){
		return ans;
	}

	return ans = max(count*v[i] + topDown(v , i+1 ,j,count+1) , count*v[j] +topDown(v , i , j-1 , count+1));
}	

ll bottomUp(vector<ll> v , ll n){
	vector<vector<ll>> dp(n+1 , vector<ll>(n+1,0));
	for(ll i=n;i>0;i--){
		for(ll j=i;j<=n;j++){
			ll year = (n-(j-i));
			if(i==j){
				dp[i][j] = n*v[i-1];
			}else{
				dp[i][j] = max(dp[i][j-1]+ year*v[j-1] , dp[i+1][j] + year*v[i-1]);
			}
		}
	}
	// for(auto c: dp){
	// 	for(auto a: c){
	// 		cout<<a<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return dp[1][n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;cin>>n;
 	vector<ll> v(n);
 	for(auto &i: v){
 		cin>>i;
 	}
 	memo.resize(n,vector<ll>(n,-1));
 	//top down
 	cout<<topDown(v , 0 , n-1 , 1)<<endl;
 	cout<<bottomUp(v , n)<<endl;
    return 0;
}