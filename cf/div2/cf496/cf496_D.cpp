#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	string s;
 	cin>>s;
 	ll ans = 0 , one = 0 , two = 0;
 	for(auto c: s){
 		ll x = c-'0';
 		bool ok = false;
 		if(x%3==0) ok = true;
 		if(x%3==1){
 			if(one>=2) ok =true;
 			if(two>=1) ok = true;
 			one++;
 		}
 		if(x%3==2){
 			if(one>=1) ok = true;
 			if(two>=2) ok = true;
 			two++;
 		}
 		if(ok){
 			ans++;
 			one = two = 0;
 		}
 	}
 	cout<<ans<<endl;
    return 0;
}