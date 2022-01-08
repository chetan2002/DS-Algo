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
    	vector<string> v(n-2);
    	for(auto &c: v) {
    		cin>>c;
    	}
    	string s = v[0];
    	for(int i=1; i<v.size(); i++) {
    		if(s.back()==v[i][0]) {
    			s+=v[i][1];
    		}else{
    			s+=v[i];
    		}
    	}
    	if(s.length()==n) {
    		cout<<s<<endl;
    	}else{
    		cout<<s+"a"<<endl;
    	}
    }
    return 0;
}