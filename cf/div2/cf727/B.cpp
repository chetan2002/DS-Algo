#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , q;
 	cin>>n>>q;
 	string s;
 	cin>>s;
 	vector<vector<ll>> fre(n,vector<ll>(26,0));
 	vector<ll> freq(26,0);
 	for(int i=0;i<s.size();i++){
 		freq[s[i]-'a']++;
 		for(int j=0;j<26;j++){
 			fre[i][j] = freq[j];
 		}
 	}
 	while(q--){
 		ll l , r;
 		cin>>l>>r;

 		l-- , r--;
 		ll sum = 0;
 		freq.clear();
 		freq.resize(26,0);
 		for(int i=0;i<26;i++){
 			ll f = fre[r][i]-(l==0 ? 0:fre[l-1][i]);
 			freq[i]=f;
 		}
 		for(int i=0;i<26;i++){
 			sum+=(freq[i]*(i+1));
 		}
 		cout<<sum<<endl;
 	}   

    return 0;
}