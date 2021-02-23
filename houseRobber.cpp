#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[100005];
ll recur(ll n , ll *arr){
	if(n<=0){
		return dp[n] = 0;
	}
    if(dp[n]!=-1){
        return dp[n];
    }

	ll first = recur(n-2 , arr ) + arr[n-1];
	ll second = recur(n-3 , arr) + arr[n-2];

	return dp[n] = max(first , second);

}

int main(){
	ll n;
    cin>>n;
	ll arr[100005];
	memset(dp , -1 , sizeof(dp));
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<recur(n , arr )<<endl;


	return 0;
}