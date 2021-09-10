#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 998244353 ;



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
    	ll maxel = *max_element(v.begin() , v.end());
    	ll countM = count(v.begin() , v.end() , maxel);
    	ll countM2 = count(v.begin() , v.end() , maxel-1);

    	ll ans = 1 , sub = 1;
    	for(int i=1;i<=n;i++){
    		ans = (ans* i)%mod;
    		if(i!=countM2+1) sub = (sub*i )%mod;
    	}

    	if(countM==1){
    		cout<<(ans - sub + mod)%mod<<endl;
    		continue;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}