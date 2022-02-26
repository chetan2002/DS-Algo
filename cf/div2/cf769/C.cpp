#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll answer(ll a, ll b) {
	if(b<=a) {
		return a-b;
	}
	if(a<b and (a|b)==b) {
		return 1;
	}

	ll count = b-a;
	if(a<b) {
		ll v = ceil(log2(b));
		for(ll i=b; i<pow(2,v+1); i++) {
			ll value =  1 + (i-b) + abs((a|i)-i);
			count = min(count,value);
		}
		for(ll i=a; i<b; i++) {
			ll value =  1 + (i-a) + abs((b|i)-b);
			count = min(count,value);
		}
	}
	return count;;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll a, b;
    	cin>>a>>b;
    	cout<<answer(a, b)<<endl;
    }
    return 0;
}