#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , l , r;
    	cin>>n>>l>>r;

    	vector<ll> v(n);
    	for(auto &c: v){
    		cin>>c;
    	}
    	sort(v.begin(),v.end());
    	ll count = 0;
    	for(ll i=0;i<n;i++){
    		auto a = lower_bound(v.begin()+i+1 , v.end() , l-v[i]);
    		if(a==v.end()){
    			continue;
    		}
    		auto b = upper_bound(v.begin()+i+1 , v.end() , r-v[i]);
    		bool check = binary_search(v.begin()+i , v.end() , l-v[i]);
    		if(b<=a){
    			continue;
    		}
    			count+=(b-a);
    		
    	}

    	cout<<count<<endl;
    }
    return 0;
}