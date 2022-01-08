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
    	if(s.length()%2==1) {
    		cout<<"NO"<<endl;
    	}else{
    		int n= s.length();
    		if(s.substr(n/2) == s.substr(0,n/2)) {
    			cout<<"YES"<<endl;
    		}else{
    			cout<<"NO"<<endl;
    		}
    	}
    }
    return 0;
}