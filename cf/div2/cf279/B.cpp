#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool answer(ll n , ll a , ll b){
	if(a==1){
		return (n-a)%b==0;
	}
	ll value = 1;
	while(value<=n){
		if((n-value)%b==0){
			return true;
		}
		value=value*a;
	}
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n ,a,b;
    	cin>>n>>a>>b;

    	if(answer(n,a,b)){
    		cout<<"Yes"<<endl;
    	}else{
    		cout<<"No"<<endl;
    	}
    }
    return 0;
}