#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(int l=1;l<=t;l++){
    	ll n, d, c, m;
    	cin>>n>>d>>c>>m;
    	string s;cin>>s;
    	bool poss = true;
    	for(auto k: s) {
    		if(k == 'C') {
    			c--;
    		}else{
    			d--;
    			if(c<0 || d<0) {
    				poss = false;
    				continue;
    			}
    			c+=m;
    		}
    		if(d<0) {
    			poss = false;
    		}
    	}

    	cout<<"Case #"<<l<<": ";
    	if(poss) {
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}