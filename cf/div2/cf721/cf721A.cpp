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

    	ll ans = log2(n);
    	ans = 1<<ans;
    	cout<<ans-1<<endl;
    }
    return 0;
}