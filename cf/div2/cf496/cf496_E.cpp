#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , k;
 	cin>>n>>k;
 	vector<ll> v(n);
 	for(int i=0;i<n;i++){
 		cin>>v[i];
 	}   
 	ll ans = 0;
 	ll pos = k-1;	
 	ll mid = (n-1)/2;
 	if(mid==pos){
 		if(n%2==0){
 			ans++;
 			n=n-1;
 		}
 		ans = ans+(2*n);
 	}
 	if(pos<mid){
 		ans = 1 +pos*2;
 	}
 	if(pos>mid){
 		ans = 1 + findAns(())
 	}
    return 0;
}