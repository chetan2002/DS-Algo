#include<bits/stdc++.h>
using namespace std;
#define ll long long int



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    vector<string> v;
    int64_t powerOf2 = 1;
    while(powerOf2<100000000000000000){
    	v.push_back(to_string(powerOf2));
    	powerOf2*=2;
    }
    while(t--){
    	string s;cin>>s;
    	ll answer = s.length()+1;
    	for(auto c: v){
    		ll j =0 ;
    		ll n = c.length();
    		ll del = 0;
    		for(int i=0;i<s.length();i++){
    			if(s[i]==c[j]){
    				j++;
    			}else{
    				del++;
    			}
    		}

    		answer = min(answer , del + n-j);
    	}
    	cout<<answer<<endl;
    }
    return 0;
}