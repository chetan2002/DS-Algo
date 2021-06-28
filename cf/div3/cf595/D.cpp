#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sum;
vector<ll> v;
void generate(ll i , ll s){
	if(i==v.size()){
		sum.push_back(s);
		return;
	}
	generate(i+1 , s);
	generate(i+1 , s+v[i]);
	return;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    ll value = 1;
    ll maxV = 1e12;
    while(value<=maxV){
    	v.push_back(value);
    	value = value*3;
    }
    generate(0 , 0);
    sort(sum.begin() , sum.end());
    // cout<<v.size()<<" "<<sum.size()<<endl;
    // for(auto c: sum){
    // 	cout<<c<<" ";
    // }
    // cout<<endl;
    while(t--){
    	ll n;cin>>n;    	
		auto it = lower_bound(sum.begin(),sum.end(),n);
		cout<<*it<<endl;
    }
    return 0;
}