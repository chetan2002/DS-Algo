//https://hack.codingblocks.com/app/contests/2022/1353/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[2005][2005][6];

ll answer(ll *arr1 , ll n , ll *arr2 , ll m , ll k){
	if(k<0){
		return LLONG_MIN;
	}
	if(n<=0 || m<=0 ){
		return 0;
	}

	ll& ans = dp[n][m][k];

	if(ans != -1){
		return ans;
	}

	ans = max(answer(arr1 , n-1 , arr2 , m , k) , answer(arr1 , n , arr2 , m-1 , k));

	if(arr1[n-1]==arr2[m-1]){
		ans = max(ans , 1+answer(arr1 , n-1 , arr2 , m-1 , k));
	}

	ans = max(ans , 1+ answer(arr1 , n-1 , arr2 , m-1 , k-1));

	return ans;

}

int main(){
	ll n , m , k;
	cin>>n>>m>>k;
	ll arr1[n+1];
	ll arr2[m+1];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}	
	for(int j=0;j<m;j++){
		cin>>arr2[j];
	}
	memset(dp , -1 , sizeof(dp));
	cout<<answer(arr1 , n , arr2 , m , k)<<endl;
	return 0;
}