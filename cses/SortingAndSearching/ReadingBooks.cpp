#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	vector<ll> v(n);
 	ll sum =0 ;
 	for(auto &c: v) {
 		cin>>c;
 		sum+=c;
 	}   
 	sort(v.begin(), v.end());
 	cout<<max(sum, v[n-1]*2)<<endl;
    return 0;
}