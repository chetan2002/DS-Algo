#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> mergeTwoArrays(vector<ll> a , vector<ll> b){
	if(a.size()==0){
		return b;
	}
	if(b.size()==0){
		return a;
	}
	vector<ll> ans;
	int i=0, j =0;
	while(i<a.size() and j<b.size()){
		if(a[i]<=b[j]){
			ans.push_back(a[i]);
			i++;
		}else{
			ans.push_back(b[j]);
			j++;
		}
	}
	while(i<a.size()){
		ans.push_back(a[i++]);
	}
	while(j<b.size()){
		ans.push_back(b[j++]);
	}
	return ans;
}

vector<ll> mergeArrays(vector<vector<ll>> &v , ll m , ll n){
	vector<ll> ans;
	for(int i=0 ;i<v.size() ; i++){
		ans = mergeTwoArrays(ans , v[i]);
	}
	return ans;
}

int main(){
	ll n , m;
	cin>>n>>m;
	vector<vector<ll>> v;
	for(int i=0 ; i<n;i++){
		vector<ll> a;
		for(int j=0;j<m;j++){
			ll val;
			cin>>val;
			a.push_back(val);
		}
		v.push_back(a);
	}	
	vector<ll> a = mergeArrays(v , m , n);
	for(auto c: a){
		cout<<c<<" ";
	}
	return 0;
}