#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	int z =0 , o = 0;
    	int prev = -1;
    	for(auto c: s) {
    		if(c=='0' and prev!=0) {
    			z++;
    			prev = 0;
    		}else
    		if(c=='1') {
    			o++;
    			prev = 1;
    		}
    	}
    	if(z==0) {
    		cout<<0<<endl;
    	}else
    	if(o==0 || z==1) {
    		cout<<1<<endl;
    	}else {
    		cout<<2<<endl;
    	}
    }
    return 0;
}