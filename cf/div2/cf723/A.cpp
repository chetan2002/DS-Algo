#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;

    	vector<ll> v(2*n);
    	for(int i=0;i<2*n;i++){
    		cin>>v[i];
    	}
    	sort(v.begin(),v.end());
    	vector<ll> ans(2*n);
    	int i=0 , j = n;
    	for(int k=0;k<2*n;k++){
    		if(k%2==0){
    			ans[k] = v[i++];
    		}else{
    			ans[k] = v[j++];
    		}
    	}
    	for(auto c: ans){
    		cout<<c<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}