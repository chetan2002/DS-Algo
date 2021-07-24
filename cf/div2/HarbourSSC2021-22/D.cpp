#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string s , t;cin>>s>>t;
    	reverse(s.begin(),s.end());
    	reverse(t.begin(),t.end());

    	int i=0;
    	bool dead = false;
    	for(auto c: s){
    		if(dead==true){
    			dead=false;
    			continue;
    		}
    		if(i==t.size()){
    			break;
    		}
    		if(c==t[i]){
    			i++;
    		}else{
    			dead=true;
    			continue;
    		}
    	}

    	if(i==t.size()){
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}

    }
    return 0;
}