#include<bits/stdc++.h>
using namespace std;

bool subsetPossible(int n , int* arr , int target){
    bool dp[n+1][target+1];

    for(int i=0;i<=n;i++){
		for(int j=0;j<=target;j++){
			dp[i][j]=false;
		}
	}

    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=target;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(j-arr[i-1]>=0){
                dp[i][j] = (dp[i-1][j-arr[i-1]])||(dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }    

	
    return dp[n][target];
}

int main(){
    int n , target;
    cin>>n>>target;
    int arr[1005];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr , arr+n);
    if(subsetPossible(n , arr , target)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}