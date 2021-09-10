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

    	string newS = "";
    	for(auto c: s){
    		if(c!='?'){
    			newS+=c;
    		}
    	}
    	s=newS;
    	if(s.find("MU")!=string::npos){
    		cout<<"Yes"<<endl;
    	}else{
    		cout<<"No"<<endl;
    	}

    }
    return 0;
}