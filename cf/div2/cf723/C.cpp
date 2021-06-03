#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void backtrack(ll n , vector<ll> v , ll &count , ll co , ll sum){
	if(sum<0){
		return;
	}
	if(n==v.size()){
		count = max(count , co);
		return;
	}
	if(v[n]<0){
		backtrack(n+1 , v , count , co , sum);
	}
	backtrack(n+1 , v , count , co+1 , sum+v[n]);
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
 	ll count = 0;
 	backtrack(0 , v , count , 0 , 0);
 	cout<<count<<endl;
    return 0;
}