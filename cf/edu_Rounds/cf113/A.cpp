#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	int n;cin>>n;
    	string s;
    	cin>>s;
    	bool ans = false;
    	for(int i=0;i<n-1;i++){
    		if((s[i]=='a' and s[i+1]=='b') || (s[i]=='b' and s[i+1]=='a')){
    			cout<<i+1<<" "<<i+2<<endl;
    			ans = true;
    			break;
    		}
    	}
    	if(!ans){
    		cout<<"-1 -1"<<endl;
    	}
    }
    return 0;
}