#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , q;
 	cin>>n>>q;

 	multiset<ll> v;
 	for(ll i = 0 ;i<n;i++){
 		ll value;
 		cin>>value;
 		v.insert(value);
 	}   

 	while(q--){
 		ll val;
 		cin>>val;

 		auto ans = v.lower_bound(val);
 		if(*ans == val){
 			cout<<val<<endl;
 			v.erase(ans);
 		}else{
 			if(ans==v.begin()){
 				cout<<"-1"<<endl;
 			}else{
 				ans--;
 				cout<<*ans<<endl;
 				v.erase(ans);
 			}
 		}
 	}
    return 0;
}