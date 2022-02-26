#include<bits/stdc++.h>
using namespace std;
#define ll long long int


char value(char c) {
	return c-'0';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	bool ans = false;
    	for(int i=s.length()-1; i>=1; i--) {
    		int val = value(s[i-1]) + value(s[i]);
    		if(val>9) {
    			s = s.substr(0, i-1) + to_string(val) +  s.substr(i+1);
    			cout<<s<<endl;
    			ans = true;
    			break;
    		}
    	}
    	if(ans) {
    		continue;
    	}
    	int val = value(s[0]) + value(s[1]);
    	if(s.size()>2) {
    		cout<<val<<s.substr(2)<<endl;
    	}else{
    		cout<<val<<endl;
    	}
    }
    return 0;
}