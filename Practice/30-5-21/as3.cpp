#include<bits/stdc++.h>
using namespace std;
#define ll long long int



bool answer(ll n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i == 0){
			return true;
		}
	}
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;cin>>t;
    while(t--){
    	ll n;cin>>n;

    	if(answer(n)){
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}