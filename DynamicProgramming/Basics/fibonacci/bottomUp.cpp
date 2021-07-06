#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll fib(ll n){
	ll arr[n+1];
	arr[0] = 0 , arr[1] = 1;
	for(ll i=2;i<=n;i++){
		arr[i] = arr[i-1]+arr[i-2];
	}
	return arr[n];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;
 	cin>>n;

 	cout<<fib(n)<<endl;   

    return 0;
}