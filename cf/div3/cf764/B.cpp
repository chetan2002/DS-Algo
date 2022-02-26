#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll a, b, c; 
    	cin>>a>>b>>c; 
    	bool ans= false;
    	ll x = 2*b - c;
    	ll m = x/a;
    	if(m>0 and x == (a*m)) ans = true;
    	if((c-a)%2 ==0) {
    		ll d = (c-a)/2;
    		x = a+d;
    		m = x/b;
    		if(m>0 and x==(b*m)) ans= true;
    	}
    	x = 2*b-a;
    	m = x/c;
    	if(m>0 and x==(c*m)) ans= true;
    	if(ans) {
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}