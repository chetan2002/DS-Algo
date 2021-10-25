#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(int l=1;l<=t;l++){
    	ll n;cin>>n;
    	string s;cin>>s;
    	vector<ll> v;
    	for(int i=0;i<n;i++){
    		char c = s[i];
    		if(c=='1'){
    			v.push_back(i);
    		}
    	}
    	ll count=0 ;
    	for(int i=0;i<n;i++){
    		auto it1 = lower_bound(v.begin(),v.end(),i);
    		if(it1==v.end()){
    			it1--;
    			count+= abs(i-*it1);
    		}else
    		if(*it1 == i){
    			continue;
    		}else
    		if(it1==v.begin()){
    			count += abs(i-*it1);
    		}else{
    			auto it2 = it1-1;
    			count += min(abs(i-*it1),abs(i-*it2));
    		}
    		
    	}
    	cout<<"Case #"<<l<<": "<<count<<endl;
    }
    return 0;
}