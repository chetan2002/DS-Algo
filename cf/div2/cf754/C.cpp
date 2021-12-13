#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    vector<string> sol= {"aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"};
    while(t--){
    	int n;cin>>n;
    	string s;cin>>s;

    	int len = 1e8;
    	for(auto c: sol) {
    		if(s.find(c)!=string::npos) {
    			len = min(len, (int)c.length());
    		}
    	}
    	if(len == 1e8) {
    		cout<<"-1"<<endl;
    	}else{
    		cout<<len<<endl;
    	}
    }
    return 0;
}