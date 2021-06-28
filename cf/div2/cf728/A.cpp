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
    	vector<ll> v(n);
    	for(int i=0;i<n;i++){
    		v[i] = i+1;
    	}

    	for(int i=0;i<n;i+=2){
    		if(i!=n-1){
    			swap(v[i],v[i+1]);
    		}
    	}
    	if(n%2!=0){
    		swap(v[n-1],v[n-3]);
    	}
    	for(auto c: v){
    		cout<<c<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}