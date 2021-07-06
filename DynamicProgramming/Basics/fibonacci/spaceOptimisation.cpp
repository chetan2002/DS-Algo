#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll fib(ll n){
	if(n<=1){
		return n;
	}
	ll One=0 , Two =1 ;
	for(ll i=2;i<=n;i++){
		One = One+Two;
		swap(One,Two);
	}
	return Two;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;cin>>n;
 	cout<<fib(n)<<endl;   

    return 0;
}