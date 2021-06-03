#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll answer(vector<ll> v){
	int n = v.size();
	vector<ll> ans(n , 0);
	for(int i=0;i<n;i++){
		ans[i] = v[i];
	}
	ll maxi = v[0];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(v[j]%v[i]==0){
				ans[j] = max(ans[j] , ans[i]+v[j]);
				maxi = max(ans[j] , maxi);
			}
		}
	}

	return maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;
 	cin>>n;

 	vector<ll> v(n);
 	for(int i=0;i<n;i++){
 		cin>>v[i];
 	}   

 	cout<<answer(v)<<endl;

    return 0;
}