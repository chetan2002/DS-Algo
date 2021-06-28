#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , k , x;
 	cin>>n>>k>>x;

 	vector<ll> v(n);
 	for(auto &c: v){
 		cin>>c;
 	}

 	sort(v.begin(),v.end());

 	ll ans = 0;
 	vector<ll> s;
 	for(int i=1;i<n;i++){
		ll val = v[i]-v[i-1];	
 		if(val>x){
 			ll r = val/x;
 			if(val%x==0){
 				r--;
 			}
 			s.push_back(r);
 			ans++;
 		}
 	}

 	sort(s.begin(),s.end());
 	for(int i=0;i<s.size();i++){
 		if(k-s[i]>=0){
 			ans-- , k-=s[i];
 		}
 	}
 	cout<<ans+1<<endl;

    return 0;
}