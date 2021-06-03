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

    	string a ="";
    	string b = "";
    	bool aGr = false;
    	for(int i=0;i<s.length();i++){
    		if(s[i]=='0'){
    			a+= '0';
    			b+='0';
    		}else
    		if(s[i]=='1'){
    			if(aGr==false){
	    			a+='1';
	    			b+='0';	
	    			aGr = true;
    			}else{
    				a+='0';
    				b+='1';
    			}
    			
    		}else{
    			
    			if(aGr==false){
	    			a+='1';
	    			b+='1';	
    			}else{
    				a+='0';
    				b+='2';
    			}
    			
    		}
    	}
    	cout<<a<<endl<<b<<endl;

    }
    return 0;
}