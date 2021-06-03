#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , a , b;
    	cin>>n>>a>>b;

    	string s;

    	string k="";
    	for(int i=0;i<b;i++){
    		k+=('a'+i);
    	}

    	while(s.length()<n){
    		s+=k;
    	}

    	s = s.substr(0,n);
    	cout<<s<<endl;
    }
    return 0;
}