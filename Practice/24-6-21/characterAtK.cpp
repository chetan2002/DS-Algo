#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<string> v;
vector<vector<ll>> fre;

void populateFre(){
	fre.resize(n+1 , vector<ll>(26,0));

	for(int i=1;i<=n;i++){
		fre[i] = fre[i-1];
		for(auto c: v[i-1]){
			fre[i][c-'a']++;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	cin>>n;
 	v.resize(n);
 	for(auto &c: v){
 		cin>>c;
 	}   
 	populateFre();
 	ll q;cin>>q;
 	while(q--){
 		ll l , r , k ;
 		cin>>l>>r>>k;

 		vector<ll> freq(26,0);
 		for(int i=0;i<26;i++){
 			freq[i] = fre[r][i] - fre[l-1][i];
 		}

 		for(int i=0;i<26;i++){
 			if(freq[i]>=k){
 				cout<<(char)('a'+i)<<endl;
 				break;
 			}else{
 				k-=freq[i];
 			}
 		}
 	}
    return 0;
}