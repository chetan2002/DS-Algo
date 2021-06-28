#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool comp(ll a , ll b){
	ll value1 = __gcd(a , 2*b);
	ll value2 = __gcd(b , 2*a);

	return value1>value2;
}

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
    	sort(v.begin(),v.end(),comp);
    	ll count = 0;
    	for(int i=0;i<n;i++){
    		for(int j=i+1;j<n;j++){
    			

    			ll gcdA = __gcd(v[i] , 2*v[j]);
    			if(gcdA>1){
    				count++;
    			}
    		}
    	}

    	cout<<count<<endl;

    }
    return 0;
}