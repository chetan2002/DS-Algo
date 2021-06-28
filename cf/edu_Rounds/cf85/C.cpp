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
    	ll a[n+1] , b[n+1];
    	for(int i=0;i<n;i++){
    		cin>>a[i]>>b[i];
    	}
    	ll ans = 0 , mn =LLONG_MAX;
    	for(int i=0;i<n;i++){
    		int nxt = (i+1)%n;
    		ll value = min(a[nxt],b[i]);
    		ans += a[nxt]-value;
    		mn = min(mn , value);
    	}
    	ans += mn;
    	cout<<ans<<endl;
    }
    return 0;
}