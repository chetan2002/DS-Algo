#include<bits/stdc++.h>
using namespace std;
#define ll long long int

//given n and k , i.e no. of steps and max jump at each steps
// find no. of ways to reach nth step

vector<int> v;

ll topDown(ll n , ll k){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	if(v[n]!=0){
		return v[n];
	}
	ll sum = 0;
	for(int i=1;i<=min(n,k);i++){
		sum+=topDown(n-i,k);
	}
	return v[n] = sum;
}

ll bottomUp(ll n , ll k){
	vector<ll> dp(n+1,0);
	dp[0] =1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i>=j){
				dp[i] += dp[i-j];
			}
		}
	}
	return dp[n];
}


// if we carefully observe the bottomUp approach here
// we can see that the numbers are forming a pattern
// they are sum of last k elements
// here we can use a sliding window
// dp[n]= 2*dp[n-1] - dp[n-k-1] 
// complexity is O(n) for Run Time
ll optimised(ll n , ll k){
	vector<ll> dp(n+1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		if(i>k){
			dp[i] = 2*dp[i-1] - dp[i-k-1];
		}else{
			dp[i] = 2*dp[i-1];
		}
	}
	return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	ll k ; cin>>k;
    	v.clear();
    	v.resize(n+1, 0);
    	cout<<topDown(n ,k)<<endl;
    	cout<<bottomUp(n,k)<<endl;
    	cout<<optimised(n,k)<<endl;
    }
    return 0;
}