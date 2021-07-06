#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
 	multiset<ll> s;   
 	for(int i=0;i<n;i++){
 		ll val;
 		cin>>val;
 		auto it = s.upper_bound(val);
 		if(it!=s.end()){
            // cout<<*it<<" "<<val<<endl;;
 			s.erase(it);
 		}
		s.insert(val);
        // for(auto c: s){
        //     cout<<c<<" ";
        // }
        // cout<<endl;
 	}
    // cout<<endl;
 	cout<<s.size()<<endl;
    return 0;
}