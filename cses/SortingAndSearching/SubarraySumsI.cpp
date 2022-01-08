#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, k;
 	cin>>n>>k;
 	vector<ll> v(n);
 	for(auto &c: v) {
 		cin>>c;
 	}
 	int s=0, e=0;
 	ll count =0;
 	ll sum =0;
 	while(e<n) {
 		sum+=v[e];
 		if(sum==k) {
 			count++;
 		}
 		if(sum<=k) {
 			e++;
 		}else{
 			while(sum>k) {
 				sum-=v[s];
 				s++;
 			}
 			sum-=v[e];
 		}
 	}
 	cout<<count<<endl;
    return 0;
}