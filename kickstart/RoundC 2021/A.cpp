#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(int l=1;l<=t;l++){
    	ll n , k;
    	cin>>n>>k;
    	string s;
    	cin>>s;
    	vector<int> fmap(26,0);
    	for(auto c: s){
    		fmap[c-'a']++;
    	}

    	string a = "";
    	for(int i=0;i<fmap.size();i++){
    		string F(fmap[i],'a'+i);
    		a+=F;
    	}

    	ll count = 0;
    	while(a<s){
    		count++;
    		cout<<a<<
    		next_permutation(a.begin(),a.end());
    	}

    	cout<<"Case #"<<l<<": "<<count<<endl;
    }
    return 0;
}