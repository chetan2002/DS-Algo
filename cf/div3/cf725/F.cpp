#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll answer(ll x){
	ll ans = 0;
	while(x>0){
		ans+=x;
		x/=10;
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll l , r;
    	cin>>l>>r;

    	cout<<answer(r)-answer(l)<<endl;

    }
    return 0;
}