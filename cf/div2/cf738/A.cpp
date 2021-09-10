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
    	ll ans;
    	cin>>ans;
    	for(int i=0;i<n-1;i++){
    		int val;
    		cin>>val;
    		ans = ans&val;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}