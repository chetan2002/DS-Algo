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
    	string s;cin>>s;

    	string a = s;
    	sort(a.begin(),a.end());
    	int count = 0;
    	for(int i=0;i<n;i++){
    		if(a[i]!=s[i]){
    			count++;
    		}
    	}
    	cout<<count<<endl;
    }
    return 0;
}