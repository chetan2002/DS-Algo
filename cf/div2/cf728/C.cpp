#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll answer(ll n , vector<ll> &v){
	if(n<=2){
		return 0;
	}
	vector<ll> ans(n);
	for(ll i=1;i<n;i++){
		ans[i] = ans[i-1]+v[i];
	}
	// for(auto c: ans){
	// 	cout<<c<<" ";
	// }
	// cout<<endl;
	ll sum =0 ;
	for(int i=2;i<n;i++){
		sum+=(ans[1]-ans[i]);
	}
	return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	vector<ll> v(n);
    	for(int i=0;i<n;i++){
    		cin>>v[i];
    	}
    	sort(v.begin(),v.end());
    	cout<<answer(n,v)<<endl;
    }
    return 0;
}