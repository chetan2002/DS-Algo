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

    	int maxi = 0;
    	while(n>0){
    		int val = n%10;
    		maxi = max(maxi , val);
    		n/=10;
    	}
    	cout<<maxi<<endl;

    }
    return 0;
}