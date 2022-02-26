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
    	for(auto &c: v) {
    		cin>>c; 
    	}
    	sort(v.begin(), v.end());
    	cout<<v[n-1]-v[0]<<endl;
    }
    return 0;
}