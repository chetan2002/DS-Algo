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
    	vector<ll> a(n);
    	vector<ll> b(n);
    	for(int i=0; i<n; i++) {
    		cin>>a[i];
    	}
		for(int i=0; i<n; i++) {
    		cin>>b[i];
    	}
    	ll maxi = a[0], mini = min(a[0],b[0]);
    	for(int i=0; i<n; i++) {
    		maxi = max(maxi, max(a[i], b[i]));
    		mini = max(mini, min(a[i], b[i]));
    	}
    	cout<<maxi*mini<<endl;
    }
    return 0;
}