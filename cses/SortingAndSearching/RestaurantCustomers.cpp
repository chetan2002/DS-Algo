#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool comp(pair<ll,bool> p1 , pair<ll,bool> p2){
	if(p1.first == p2.first){
		return p1.second;
	}
	return p1.first<p2.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;cin>>n;
 	vector<pair<ll,bool>> vp;
 	for(int i=0;i<n;i++){
 		ll value;
 		cin>>value;
 		vp.push_back({value,true});
 		cin>>value;
 		vp.push_back({value,false});
 	}
 	sort(vp.begin(),vp.end() , comp);
 	ll count = 0;
 	ll _max = 0;
 	for(auto c: vp){
 		if(c.second){
 			count++;
 		}else{
 			count--;
 		}

 		_max = max(_max,count);
 	}
 	cout<<_max<<endl;
    return 0;
}