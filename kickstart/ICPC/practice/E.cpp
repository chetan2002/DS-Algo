#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1000000007;

ll answer(vector<ll> v){
	ll n = v.size();
	ll sum = 0 , mul = 1;
	for(ll i =0 ;i<30;i++){
		ll c_odd = 0;
		bool odd= 0 ;
		for(int j=0;j<n;j++){
			if((v[j]&(1<<i))>0){
				odd = (!odd);
			}
			if(odd)	c_odd++;
			
		}
		for (ll j = 0; j < n; j++) {
            sum += (mul * c_odd);
 
            if ((v[j] & (1 << i)) > 0)
                c_odd = (n - j - c_odd);
	        

	        sum = sum%mod;
        }
        mul*=2;
	}
	return sum%mod;
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
    	for(auto &c: v){
    		cin>>c;
    	}
    	cout<<answer(v)<<endl;	
    }
    return 0;
}