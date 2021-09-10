#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , k;
 	cin>>n>>k;   
 	string s;
 	cin>>s;

 	for(int i=0;i<26;i++){
 		string a="";
 		for(auto c: s){
 			if(c=='a'+i and k!=0){
 				k--;
 				continue;
 			}else{
 				a+=c;
 			}
 		}
 		s = a;
 		if(k==0){
 			break;
 		}
 	}
 	cout<<s<<endl;
    return 0;
}