//https://hack.codingblocks.com/app/contests/2022/720/problem

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

void permutate(ll *arr , ll n , ll k){
	unordered_map<ll , ll> mp;
	for(int i=0;i<n;i++){
		mp.insert({arr[i] , i});
	}
	for(int i=n;i>0;i--){
		if(k>0){
			ll element = i;
			ll position = mp[i];
			ll elementAtPos = arr[n-i];
			ll moveToPos = n-i;
			if(position!=moveToPos){
				swap(arr[position] , arr[moveToPos]);
				mp[element]=moveToPos;
				mp[elementAtPos] = position;
				k--;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	ll n , k;
	cin>>n>>k;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	permutate(arr , n , k);
	return 0;
}