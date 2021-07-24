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
    	int n = s.length();
    	int i=0 , j = n-1;
    	int val = max(s[i],s[j])+1;
    	bool ans = true;
    	while(i<j){
    		if(s[i]==val-1){
    			val = s[i];
    			i++;
    		}else
    		if(s[j]==val-1){
    			val = s[j];
    			j--;
    		}else{
    			ans = false;
    			break;
    		}	
    	}
    	if(!ans){
    		cout<<"NO"<<endl;
    	}else{
    		if(s[i]=='a' and val-1==s[i]){
    			cout<<"YES"<<endl;
    		}else{
    			cout<<"NO"<<endl;
    		}
    	}
    }
    return 0;
}