#include<bits/stdc++.h>
using namespace std;

int answer(int* wt , int* value , int n , int k){
	if(n<=0){
		return 0;
	}
	int dp[n+1][k+1]={0};
	for(int i=1 ; i<=n;i++){
		dp[i][0]=0;
		for(int j=1;j<=k;j++){
			dp[0][j]=0;
			if(j-wt[i-1]>=0){
				dp[i][j] = max(dp[i-1][j-wt[i-1]]+value[i-1] , dp[i-1][j]);
			}else{
				dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
			}
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	return dp[n][k];
}

int main(){
	int n , k;
	cin>>n>>k;
	int wt[n] , value[n];
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	for(int i=0;i<n;i++){
		cin>>value[i];
	}

	cout<<answer(wt , value , n , k)<<endl;

	return 0;
}


// 5 4
// 1 2 3 2 2 
// 8 4 0 5 3


//13