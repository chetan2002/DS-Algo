#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
		ll n , m;
		cin>>n>>m;

		vector<vector<ll>> v; 
		for(int i=0;i<n;i++){
			ll t , l , h;
			cin>>t>>l>>h;

			v.push_back({t,l,h});
		}    	

		bool pos = true;

		ll low = m , high = m;

		ll t = 0;
		for(auto c: v){
			ll dur = c[0]-t;
			t = c[0];
			if(c[2]<low-dur){
				pos = false;
				break;
			}
			if(c[1]>high+dur){
				pos = false;
				break;
			}
			// cout<<low<<" "<<high<<endl;
			low = max(low-dur , c[1]);
			high = min(high+dur , c[2]);
			// cout<<low<<" "<<high<<endl;

		}
		if(pos){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
    }
    return 0;
}