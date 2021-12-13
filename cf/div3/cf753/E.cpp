#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n, m;cin>>n>>m;
    	string s;cin>>s;

    	ll lmax =0, rmax =0;
    	ll umax =0, dmax =0;
    	ll x =0, y =0;
    	for(auto c: s) {
    		if(c=='U') {
    			x--;
    		}else
    		if(c=='D') {
    			x++;
    		}else
    		if(c=='L'){
    			y--;
    		}else{
    			y++;
    		}
    		lmax = min(lmax, y);
    		rmax = max(rmax, y);
    		umax = min(umax, x);
    		dmax = max(dmax, x);
    		if (rmax-lmax>=m || dmax-umax>=n) {
    			if(c=='U') {
	    			umax++;
	    		}else
	    		if(c=='D') {
	    			dmax--;
	    		}else
	    		if(c=='L'){
	    			lmax++;
	    		}else{
	    			rmax--;
	    		}
    			break;
    		}
    	}
		
		ll valx = ((0-umax) + (n-dmax))/2;
		ll valy = ((0-lmax) + (m-rmax))/2;
		cout<<valx+1<<" "<<valy+1<<endl;

    }
    return 0;
}