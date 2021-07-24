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
    	ll count = n/10;
    	if(n%10==9){
	    	count++;
    	}
    	cout<<count<<endl;

    }
    return 0;
}