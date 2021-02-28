#include<bits/stdc++.h>
using namespace std;

int ans(int n , int *arr){
	
	int prefix[n]={0};
	prefix[0]=1;
	for(int i=1;i<n;i++){
		prefix[i]=1;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] and prefix[i]<=prefix[j])
			{
				prefix[i] = prefix[j]+1;
			}
		}
		// cout<<prefix[i]<<" ";
	}
	// cout<<endl;
	
	int suffix[n]={0};
	suffix[n-1]=1;
	for(int i=n-2;i>=0;i--){
		suffix[i] = 1;
		for(int j=n-1;j>i;j--){
			if(arr[i]>arr[j] and suffix[i]<=suffix[j]){
				suffix[i] = suffix[j]+1;
			}
		}		
		// cout<<suffix[i]<<" ";
	}
	// cout<<endl;
	int maxi = -1;
	for(int i=0;i<n;i++){
		maxi = max(maxi , prefix[i] + suffix[i] -1);
	}
	return maxi;
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
	}
	return 0;
}