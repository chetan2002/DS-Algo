#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> a = {11 , 111 , 11111 , 1111111 , 111111111};

bool tryi(ll x){
	ll val = 11*111 - 11 - 111;
		
	if(x>val){
		return true;
	}

	for(int i=0;i<=val/11;i++){
		for(int j=0;j<=val/111;j++){
			ll value = i*11 + j*111;
			if(value==x){
				return true;
			}
		}
	}

	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll x;
    	cin>>x;
    	bool ans = tryi(x);
    	if(ans){
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}