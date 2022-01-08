#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int val(char c) {
	return c-'0';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string a, s;
    	cin>>a>>s;
    	reverse(a.begin(), a.end());
    	reverse(s.begin(), s.end());
    	string b = "";
    	int i=0;
    	bool pos = true;
    	for(auto c: a) {
    		if(i>=s.length()) {
    			pos = false;
    			break;
    		}
    		if(s[i]<c) {
    			if(i==s.length()-1 or s[i+1]!='1') {
    				pos = false;
    				break;
    			}
    			int value = val(s[i]) + 10 - val(c);
    			b += to_string(value);
    			i+=2;
    		}else{
    	
    			int value = val(s[i]) - val(c);
    			b += to_string(value);
    			i++;
    		}
    	}
    	if(!pos) {
    		cout<<"-1"<<endl;
    		continue;
    	}
    	if(i<s.length()) {
    		b += s.substr(i);
    	}
    	reverse(b.begin(), b.end());
    	cout<<stoll(b)<<endl;
    }
    return 0;
}