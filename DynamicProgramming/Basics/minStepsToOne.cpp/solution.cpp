#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v;


// n = n/3 -> if n%3 ==0
// n = n/2 -> if n%2 ==0
// n = n-1


ll topDown(ll n){
	if(n==1){
		return 0;
	}
	if(v[n]!=-1){
		return v[n];
	}
	ll a1 = INT_MAX , a2 = INT_MAX , a3 = INT_MAX;
	if(n%3==0){
		a1 = topDown(n/3);
	}
	if(n%2 == 0){
		a2 = topDown(n/2);
	}
	a3 = topDown(n-1);
	return v[n]=1+min(a1 , min(a2 , a3));
}

ll bottomUp(ll n){
	ll arr[n+1];
	arr[0] = 0;
	arr[1] = 0;
	for(ll i=2;i<=n;i++){
		ll ans = arr[i-1];
		if(i%3==0){
			ans = min(ans , arr[i/3]);
		}
		if(i%2==0){
			ans = min(ans , i/2);
		}
		arr[i] = 1+ans;
	}
	return arr[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;cin>>n;
 	v.clear();
 	v.resize(n+1 , -1);
 	cout<<topDown(n)<<endl;
 	cout<<bottomUp(n)<<endl;
    return 0;
}