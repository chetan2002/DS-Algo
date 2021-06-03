#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll t;cin>>t;
 	while(t--){
 		string s(200,'a');
 		int n;cin>>n;
 		vector<int> v(n);
 		for(int i=0;i<n;i++){
 			cin>>v[i];
 		}
 		cout<<s<<endl;
 		for(int i=1;i<=n;i++){
 			int val = v[i-1];
 			if(s[val]=='a'){
 				s[val]='b';
 			}else{
 				s[val]='a';
 			}
 			cout<<s<<endl;
 		}
 	}   
    return 0;
}