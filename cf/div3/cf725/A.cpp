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
    	ll grate = 0;
    	ll low = LLONG_MAX;
    	for(int i=0;i<n;i++){
    		cin>>v[i];
    		grate = max(grate , v[i]);
    		low = min(low , v[i]);
    	}

	   	ll ind1 = 0;
	   	ll ind2 = 0;
	   	for(int i=0;i<n;i++){
	   		if(v[i] == grate){
	   			ind1 = i+1;
	   		}
	   		if(v[i]==low){
	   			ind2 = i+1;
	   		}
	   	}

	   	ll val1 = max(ind1 , ind2);
	   	ll val2 = max(n-ind1+1 , n-ind2+1);
	   	ll val3 = ind1 + (n-ind2+1);
	   	ll val4 = ind2 + (n-ind1+1);
	   	cout<<min(val1 , min(val2 , min(val3,val4)))<<endl;;

    }
    return 0;
}