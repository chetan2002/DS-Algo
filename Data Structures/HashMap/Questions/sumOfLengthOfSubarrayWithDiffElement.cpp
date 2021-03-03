// https://hack.codingblocks.com/app/contests/2022/734/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll mod = 1000000007;

ll answer(ll *arr , ll n){
	ll j=0 , ans = 0;
	unordered_set<ll> s;
	for(int i=0;i<n;i++){
		while(j<n and s.find(arr[j])==s.end()){
			s.insert(arr[j]);
			j++;

		}

		ans += (j-i)*(j-i+1)/2;
		ans = ans%mod;

		s.erase(arr[i]);
	}
	return ans;
}

int main(){
	ll n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<answer(arr , n)<<endl;
	return 0;

}