#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n1 , n2 , n3;
    	cin>>n1>>n2>>n3;

    	set<ll> s1, s2,s3;
    	for(ll i=0;i<n1;i++){
    		ll val;cin>>val;
    		s1.insert(val);
    	}
    	for(ll i=0;i<n2;i++){
    		ll val;cin>>val;
    		s2.insert(val);
    	}
    	for(ll i=0;i<n3;i++){
    		ll val;cin>>val;
    		s3.insert(val);
    	}

    	ll answer = LLONG_MAX;
    	for(auto c: s1){
    		auto a1 = s2.lower_bound(c);
    		auto a2 = s3.lower_bound(c);

    		ll val1 = abs(c-*a1);
    		ll val2 = abs(c-*a2);
    		ll val3 = abs(*a1-*a2);


    		ll ans = pow(val1,2) + pow(val2 , 2) + pow(val3,2);
    		answer = min(answer , ans);
    	}
    	for(auto c: s2){
    		auto a1 = s1.lower_bound(c);
    		auto a2 = s3.lower_bound(c);

    		ll val1 = abs(c-*a1);
    		ll val2 = abs(c-*a2);
    		ll val3 = abs(*a1-*a2);


    		ll ans = pow(val1,2) + pow(val2 , 2) + pow(val3,2);
    		answer = min(answer,ans);
    	}
    	for(auto c: s3){
    		auto a1 = s2.lower_bound(c);
    		auto a2 = s1.lower_bound(c);

    		ll val1 = abs(c-*a1);
    		ll val2 = abs(c-*a2);
    		ll val3 = abs(*a1-*a2);


    		ll ans = pow(val1,2) + pow(val2 , 2) + pow(val3,2);
    		answer = min(answer,ans);
    	}
    	
    	cout<<answer<<endl;
    }
    return 0;
}