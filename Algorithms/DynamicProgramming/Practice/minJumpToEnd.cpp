#include<bits/stdc++.h>
using namespace std;


int ans(int n , int* arr){

	int dp[n+1];
	for(int i=0;i<n;i++){
		dp[i]=n;
	}
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<min(n,i+arr[i]+1);j++){
			dp[j] = min(dp[j],dp[i]+1);
		}
		// cout<<dp[i]<<" ";
	}
	// cout<<endl;
	return dp[n-1];

}

int recursion(int n ,int i, int *arr , int *dp){
	if(i>=n){
		return dp[i]=0;
	}
    if(dp[i]!=-1){
        return dp[i];
    }
	int ans = n;
	for(int j=i+1;j<=min(n,i+arr[i]);j++){
		ans = min(ans , recursion(n , j, arr , dp));
	}
	return dp[i]=1+ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		cout<<ans(n , arr)<<endl;
        int dp[n+1];
        memset(dp, -1 , sizeof(dp));
        cout<<recursion(n , 0 , arr , dp)<<endl;
	}
	return 0;
}