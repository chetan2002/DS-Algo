#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[100005];
ll recur(ll n , ll *arr){

	if(n==0){
		return dp[n] = arr[n];
	}
	if(n==1){
		return dp[n] = max(arr[n-1] , arr[n]);
	}
    if(dp[n]!=-1){
        return dp[n];
    }

	int first = arr[n]+recur(n-2 , arr);
	int second = recur(n-1 , arr);

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

	cout<<recur(n-1 , arr )<<endl;


	return 0;
}