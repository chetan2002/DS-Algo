#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a , b , c;

bool answer(){

	ll sum = a+b+c;
	if(sum%4!=0){
		return false;
	}
	ll val = sum/4;
	if(a<val || b<val || c<val){
		return false;
	}
	if(a>2*val || b>2*val || c>2*val){
		return false;
	}
	return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	cin>>a>>b>>c;
    	
    	bool ans = answer();
    	if(ans){
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}