#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v;

ll fib(ll n){
	if(n<=1){
		return n;
	} 
	if(v[n]!=-1){
		return v[n];
	}
	return v[n]=fib(n-1)+fib(n-2);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;
 	cin>>n;
 	v.clear();
 	v.resize(n+1,-1);
 	cout<<fib(n)<<endl;   
    return 0;
}