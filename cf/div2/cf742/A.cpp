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
    	string s;
    	cin>>s;
    	string a="";
    	for(auto c: s){
    		if(c=='L'){
    			a+='L';
    		}else
    		if(c=='R'){
    			a+='R';
    		}else
    		if(c=='D'){
    			a+='U';
    		}else
    		if(c=='U'){
    			a+='D';
    		}
    	}
    	cout<<a<<endl;
    }
    return 0;
}