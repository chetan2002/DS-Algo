#include<bits/stdc++.h>
using namespace std;
#define ll long long int


// bool answer(ll a, ll b, ll c, ll m) {
	
// 	if(a+b+c-3>=m and ((a+b>=c-m-2) and (b+c>=a-m-2) and (a+c>=b-m-2))) {
// 		return true;
// 	}
// 	return false;
// }
bool answer(ll a, ll b, ll c, ll m) {
	ll maxi = max(a,c);
	maxi= max(b,maxi);
	int x = (2*maxi - (a+b+c) -1) >0 ? (2*maxi - (a+b+c) -1 ): 0;
	if(a+b+c-3>=m and m>=x) {
		return true;
	}
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll a, b, c , m;
    	cin>>a>>b>>c>>m;
    	bool ans = answer(a,b,c,m);
    	if (ans) {
    		cout<<"YES"<<endl;
    	} else {
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}