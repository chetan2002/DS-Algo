#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool comp(pair<ll,ll> p1 , pair<ll,ll> p2){
	if(p1.second==p2.second){
		return p1.first<p2.first;
	}
	return p1.second<p2.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n ;
 	cin>>n;

 	vector<pair<ll,ll>> vp(n);
 	for(auto &i: vp){
 		cin>>i.first;
 		cin>>i.second;
 	}   

 	sort(vp.begin(),vp.end(),comp);
 	ll count = 0;
 	ll end = 0;
 	for(auto c: vp){
 		if(c.first>=end){
 			end = c.second;
 			count++;

 		}
 	}
 	cout<<count<<endl;
    return 0;
}