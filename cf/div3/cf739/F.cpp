#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string s ;
    	ll k;
    	cin>>s>>k;
    	int n = s.length();
    	unordered_map<char , int> mp;
    	for(auto c: s){
    		mp[c]++;
    	}
    	if(mp.size()<=k){
    		cout<<s<<endl;
    		continue;
    	}


    	if(k==1){
    		char c = s[0];
    		string a(n, c);
    		if(s<=a){
    			cout<<a<<endl;
    			continue;
    		}

    		c++;

    		a="";
    		a.resize(n, c);
    		cout<<a<<endl;
    		continue;
    	}


    	char c1=s[0];
    	string a="";
    	char c2='a';
    	int i=0;
    	while(i<n){
    		if(s[i]==c1){
    			i++;
    			continue;
    		}else
    		if(c2!='a' and (s[i]<=c2 || s[i]<=c1)){
    			i++;
    			continue;
    		}else
    		if(c2=='a'){
    			c2 = s[i];
    		}else{
    			break;
    		}
    		i++;
    	}

    	if(i!=n){
    		c2++;
    	}
    	if(c1==c2){
    		c2= '0';
    	}
    	for(i=0;i<n;i++){
    		if(c1==s[i] || c2==s[i]){
    			if(c1==s[i]){
    				a+=c1;
    			}else{
    				a+=c2;
    			}
    		}else{
    			break;
    		}
    	}

    	char mini = min(c1,c2);
    	char maxi = max(c1,c2);
    	if(s[i]<mini){
    		string d(n-a.length(),mini);
    		a+=d;
    	}else{
    		a+=maxi;
    		string d(n-a.length(),mini);
    		a+=d;
    	}
    	cout<<a<<endl;
    }
    return 0;
}