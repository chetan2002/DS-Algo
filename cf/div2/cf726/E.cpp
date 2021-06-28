#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	int n , k;
 	cin>>n>>k;
 	string s;cin>>s;
    // cout<<s.length()<<endl;
    // return 0;
 	string b="";
 	for(int i=0;i<k;i++){
        if(s.length()-1<i){
            s+=s;
        }
        // cout<<i<<" ";
        b+=s[i];
 		string c=s.substr(i+1); 	
 		if(c>b){
 			while(b.length()<k){
 				b+=b;
 			}
 			s=b;
 		}
 	}
 	s = s.substr(0,k);
 	cout<<s<<endl;

    return 0;
}