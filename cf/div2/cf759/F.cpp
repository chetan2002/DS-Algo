#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	vector<ll> v(n);
 	for(auto &c: v) {
 		cin>>c;
 	}
 	if(n==1){
 		cout<<v[0]<<endl;
 		return 0;;
 	}
 	ll count =v[0];
 	for(int i=1; i<n-1; i++) {
 		if(v[i]==1 and (v[i-1]!=1 or v[i+1]!=1)) {
 			continue;
 		}else{
 			if(v[i-1]==1 and v[i+1]==1) {
 				count = (count*(v[i]-1))%mod;
 			}else
 			if(v[i+1]==1){
 				count = ((count*(v[i]-2))%mod + (count*(v[i]-1))%mod)%mod;
 			}else{
 				count = (count*(v[i]-1))%mod;
 			}
 		}
 	}
 	if(v[n-1]!=1) {
	 	count = (count*(v[n-1]-1))%mod;
 	}
 	cout<<count<<endl;
    return 0;
}