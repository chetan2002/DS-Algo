#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;cin>>n;
	vector<pair<ll,ll>> vp(n);
	for(auto &i: vp){
		cin>>i.first;
		cin>>i.second;
	}			   
	sort(vp.begin(),vp.end());
	vector<int> sup(n,0);
	vector<int> sub(n,0);

	int i = 0 , j=0;
	stack<int> s;
	while(j<n){
		
	}
    return 0;
}