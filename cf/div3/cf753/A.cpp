#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string m;
    	cin>>m;
    	string s;
    	cin>>s;
    	unordered_map<char, int> mp;
    	for(int i=0; i<m.length(); i++) {
    		mp[m[i]] = i;
    	}
    	int i = mp[s[0]];
    	int count = 0;
    	for(auto c: s) {
    		count += abs(mp[c]-i);
    		i = mp[c];
    	}
    	cout<<count<<endl;
    }
    return 0;
}