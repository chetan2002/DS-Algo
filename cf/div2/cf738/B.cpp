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
    	string s;cin>>s;

    	int start = 0;
    	while(start<n and s[start]=='?'){
    		start++;
    	}


    	if(start == n){
    		for(int i=0;i<n;i++){
    			if(i%2==0){
    				s[i] = 'R';
    			}else{
    				s[i] = 'B';
    			}
    		}
    		cout<<s<<endl;
    		continue;
    	}
    	for(int i=start-1;i>=0;i--){
    		if(s[i+1]=='B'){
    			s[i] = 'R';
    		}else
    		if(s[i+1]=='R'){
    			s[i] = 'B';
    		}
    	}
    	char shouldbe = s[start];
    	for(int i=start;i<s.length();i++){
    		if(s[i]=='?'){
    			s[i] = shouldbe;
    		}
		
			if(s[i]=='R'){
				shouldbe = 'B';
			}else
			if(s[i] == 'B'){
				shouldbe = 'R';
			}
    	}
    	cout<<s<<endl;
    }
    return 0;
}