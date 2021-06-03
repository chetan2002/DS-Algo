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

    	ll total;
    	cin>>total;
    	sort(v.begin(),v.end());
    	ll val1 = 0 , val2 = INT_MAX;
    	for(int i=0;i<n;i++){
    		for(int j=i+1;j<n;j++){
    			int to = v[i]+v[j];
    			if(to==total){
    				int a1 = abs(val1-val2);
    				int a2 = abs(v[i]-v[j]);
    				if(a2<a1){
    					val1 = v[i];
    					val2 = v[j];
    				}
    			}
    		}
    	}

    	cout<<"Deepak should buy roses whose prices are "<<val1<<" and "<<val2<<"."<<endl;

    }
    return 0;
}