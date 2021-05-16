#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n);
		for(ll i=0;i<n;i++){
			cin>>v[i];
		}

		vector<ll> b(v);
		sort(b.begin() , b.end());
		if(v==b){
			cout<<0<<endl;
		}else{
			if(v[0]==1 || v[n-1]==n){
				cout<<1<<endl;
			}else
			if(v[0]==n and v[n-1]==1){
				cout<<3<<endl;
			}else
			{
				cout<<2<<endl;
			}
		}
    }
    return 0;
}