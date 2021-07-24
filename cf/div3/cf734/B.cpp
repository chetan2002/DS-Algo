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

    	unordered_map<char , int> mp;
    	for(auto c: s){
    		mp[c]++;
    	}

    	int count = s.length();
    	for(auto c: mp){
    		if(c.second>2){
    			count-=c.second;
    			count+=2;
    		}
    	}
    	cout<<count/2<<endl;
    }
    return 0;
}