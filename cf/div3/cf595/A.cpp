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
    		cin>>v[i];
    	}

    	sort(v.begin(),v.end());
    	int count =1;
    	for(int i=1;i<n;i++){
    		if(v[i-1]+1==v[i]){
    			count = 2;
    		}
    	}
    	cout<<count<<endl;
    }
    return 0;
}