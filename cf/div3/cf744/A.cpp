#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string s;cin>>s;
    	int a = 0 , b = 0 , k =0 ;
    	for(auto c: s) {
    		if(c=='A') {
    			a++;
    		}
    		if ( c== 'B' ) {
    			b++;
    		}
    		if(c=='C') {
    			k++;
    		}
    	}
    	if(a+k == b) {
    		cout<<"YES"<<endl;
    	}else {
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}