#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	vector<ll> v(n);
    	ll sum = 0;
    	for(auto &i: v){
    		cin>>i;
    		sum+=i;
    	}

    	sum = sum%n;
		cout<<(n-sum)*(sum)<<endl;
    }
    return 0;
}