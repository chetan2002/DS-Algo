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
    	string s;
    	cin>>s;
    	if(s.length()==1) {
    		cout<<"YES"<<endl;
    	}else
    	if(s.length()<=2) {
    		if(s!="11" and s!="00") {
    			cout<<"YES"<<endl;
    		}else {
    			cout<<"NO"<<endl;
    		}
    	}else {
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}