#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll a ,b ;
    	cin>>a>>b;
    	if(a==b){
    		cout<<0<<endl;
    		continue;
    	}
    	ll maxi = max(b , a);
    	ll maxi2 = (maxi/2)  + 1;
    	if(min(a,b)<=maxi2){
    		cout<<maxi%maxi2<<endl;
    	}else{
    		cout<<maxi%min(a,b)<<endl;
    	}
    }
    return 0;
}