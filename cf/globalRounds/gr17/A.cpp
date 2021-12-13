#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n, m;
    	cin>>n>>m;
    	if(n==1 and m==1) {
    		cout<<0<<endl;
    	}
    	else{
    		cout<<min(n, min(m, 2ll))<<endl;
    	}
    }
    return 0;
}