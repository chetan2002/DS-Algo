#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool ans(ll n, ll m , ll k) {

	if(n==1) {
		if(m!=0) {
			return false;
		}
		return true;
	}
	if(k<=2) {
		return false;
	}
	if(n==2) {
		if(m!=1) {
			return false;
		}
		return true;
	}
	if(n==3) {
		if(m==2) {
			if(k>3){ 
				return true;
			}
			return false;
		}
		if(m==3){
			if(k>2) {
				return true;
			}
			return false;
		}
		return false;
	}

	if(k>3) {
		if(n*(n-1)/2 <m) {
			return false;
		}
		if(m<n-1) {
			return false;
		}
		return true;
	}
	if(k==3) {
		if(m==n*(n-1)/2){
			return true;
		}
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
    	ll n , m , k;

    	cin>>n>>m>>k;

    	if(ans(n,m,k)) {
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}

    }
    return 0;
}