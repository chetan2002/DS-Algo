#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n ;
    	cin>>n;
    	vector<ll> v;
    	for(int i=0;i<n;i++){
    		ll val;
    		cin>>val;
    		v.push_back(val);
    	}
    	cout<<n*3<<endl;
    	for(int i=0;i<n/2;i++){
    		ll pos1 = i+1 , pos2 = n-i;
    		// ll val1 = v[i] , val2 = v[pos2];
    		// val1 = val1+val2;
    		// val2 = val2-val1;
    		// val1 = val1+val2;
    		// val1 = val1 + val2;
    		// val2 = val2-val1;
    		// val1 = val1 + val2;
    		// v[pos1] = val1;
    		// v[pos2] = val2;
    		cout<<1<<" "<<pos1<<" "<<pos2<<endl;
    		cout<<2<<" "<<pos1<<" "<<pos2<<endl;
    		cout<<1<<" "<<pos1<<" "<<pos2<<endl;
    		cout<<1<<" "<<pos1<<" "<<pos2<<endl;
    		cout<<2<<" "<<pos1<<" "<<pos2<<endl;
    		cout<<1<<" "<<pos1<<" "<<pos2<<endl;
    	}
    	// for(auto c: v){
    	// 	cout<<c<<" ";
    	// }
    	// cout<<endl;

    }
    return 0;
}