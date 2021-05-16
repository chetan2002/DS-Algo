#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll answer(ll n){
	if(n==0){
		return 1;
	}
	if(n==100){
		return 1;
	}
	ll w = 0 , e = 1;
	ll steps = 1;
	while(true){
		double per = (1.0*(e*100))/(1.0*(w+e));
		if(per==n){
			break;
		}else
		if(per>n){
			steps++;
			w++;
		}else{
			steps++;
			e++;
		}
	}
	return steps;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	cout<<answer(n)<<endl;
    }
    return 0;
}