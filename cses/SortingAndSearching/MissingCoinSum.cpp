#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;cin>>n;
 	vector<ll> v(n);
 	for(auto &i: v){
 		cin>>i;
 	}   
 	sort(v.begin(),v.end());

 	ll ans = 1;
 	for(auto c: v){
 		if(ans<c){
 			break;
 		}else{
 			ans += c;
 		}
 	}
 	cout<<ans<<endl;
    return 0;
}