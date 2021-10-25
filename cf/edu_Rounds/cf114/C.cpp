#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	vector<ll> v(n);
 	ll totalSum =0 ;
 	for(auto &c: v){ 
 		cin>>c;
 		totalSum+=c;
 	}
 	sort(v.begin(), v.end());
 	ll m;cin>>m;
 	while(m--) {
 		ll d, a;
 		cin>>d>>a;

 		//case 1 when attack satisfy
 		auto it = lower_bound(v.begin(), v.end(), d);
 		ll attack1 = 0 , attack2 = 0;
 		if(it==v.end()) {
 			attack1 = v.back();
 			ll costD = totalSum-attack1;
 			if(costD<a) {
 				cout<<d-attack1 + a-costD<<endl;
 			}else{
 				cout<<d-attack1<<endl;
 			}
 			continue;
 		}
 		attack1= *it;
 		if(it==v.begin()) { 		
 			ll costD = totalSum-attack1;
 			if(costD<a) {
 				cout<<a-costD<<endl;
 			}else{
 				cout<<0<<endl;
 			}
 			continue;	
 		}
 		it--;
 		attack2 = *it;

 		ll value1 = LLONG_MAX , value2 = LLONG_MAX;
 		ll costD1 = totalSum-attack1 , costD2 = totalSum-attack2;
 		if(costD1<a) {
 			value1 = a-costD1;
 		}else{
 			cout<<0<<endl;
 			continue;
 		}
 		if(costD2<a) {
 			value2 = a-costD2 + d-attack2;
 		}else{
 			value2 = d-attack2;
 		}
 		cout<<min(value2,value1)<<endl;
 	}
    return 0;
}