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
    	string s;
    	cin>>s;
    	int total =0 ;
    	for(auto c: s) {
    		if(c!='0'){
    			total += c-'0';
    			total++;
    		}
    	}
    	if(s[n-1]!='0'){
    		total--;
    	}
    	cout<<total<<endl;
    }
    return 0;
}