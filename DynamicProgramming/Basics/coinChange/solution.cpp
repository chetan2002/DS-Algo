#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll v[100000];

ll topDown(ll n , ll* arr , ll sum){
	if(sum==0){
		return 0;
	}
	if(v[sum]!=-1){
		return v[sum];
	}
	ll ans = INT_MAX;
	for(ll i=0;i<n;i++){
		if(sum-arr[i]>=0){
			ans = min(ans , topDown(n , arr , sum-arr[i]));
		}
	}
	return v[sum] = 1+ans;
}

ll bottomUp(ll n , ll *arr , ll sum){
	vector<ll> dp(sum+1 , INT_MAX);
	dp[0]= 0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=sum;j++){
			if(j-arr[i]>=0){
				dp[j] = min(dp[j] , 1+dp[j-arr[i]]);
			}
		}
	}
	return dp[sum];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , sum;
 	cin>>n>>sum;
 	ll arr[n];
 	for(int i=0;i<n;i++){
 		cin>>arr[i];
 	}
 	sort(arr,arr+n);
 	memset(v , -1 , sizeof(v));
 	cout<<topDown(n , arr , sum)<<endl;
 	cout<<bottomUp(n , arr , sum)<<endl;
    return 0;
}