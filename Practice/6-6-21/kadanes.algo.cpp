#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n ;
vector<ll> v;

// maximum subarray sum = O(n*n*n)
ll brute(){
	ll  maximumSum = 0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			ll sum = 0;
			for(int k=i;k<=j;k++){
				sum+=v[k];
			}
			maximumSum = max(maximumSum , sum);
		}
	}

	return maximumSum;
}

// optimised brute
ll bruteNot(){
	ll maximumSum = 0;
	for(int i=0;i<n;i++){
		ll sum = 0;
		for(int j=i;j<n;j++){
			sum+=v[j];
			maximumSum = max(maximumSum,sum);
		}
	}
	return maximumSum;
}

// kadane's algo

ll kadane(){
	ll maxi = 0 , sum = 0;

	for(int i=0;i<n;i++){
		sum = max(v[i] , sum+v[i]);
		maxi = max(sum , maxi);
	}
	return maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	cin>>n;
 	v.resize(n);

 	
 	for(int i=0;i<n;i++){
 		cin>>v[i];
 	}   


 	//!brute
 	cout<<bruteNot()<<endl;
 	//maximum subarray sum
 	cout<<brute()<<endl;
 	cout<<kadane()<<endl;	

    return 0;
}