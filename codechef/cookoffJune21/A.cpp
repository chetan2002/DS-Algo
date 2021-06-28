#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , q;
 	cin>>n>>q;
 	vector<ll> v(n);
 	for(auto &c: v){
 		cin>>c;
 	}   
 	sort(v.begin(),v.end());
 	while(q--){
 		ll ans = 0;
 		ll value;
 		cin>>value;
 		bool present = binary_search(v.begin() , v.end() , value);
 		if(present){
 			cout<<0<<endl;
 			continue;
 		}
 		auto it = upper_bound(v.begin(),v.end(),value);
 		int val = it - v.begin();
 		if(val%2==0){
 			cout<<"POSITIVE"<<endl;
 		}else{
 			cout<<"NEGATIVE"<<endl;
 		}
 	}

    return 0;
}