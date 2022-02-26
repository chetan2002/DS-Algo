#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll answer(int i, vector<ll> &v, ll x) {
	if(i == v.size()) {
		return 0;
	}
	
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, x; 
 	cin>>n>>x;  

 	vector<ll> v(n);
 	for(auto &c: v) {
 		cin>>c; 
 	}   
 	sort(v.begin(), v.end(), greater<ll>());
	cout<<answer(0, v, x)<<endl;
    return 0;
}