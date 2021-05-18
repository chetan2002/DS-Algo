#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll answer(ll d , ll n , vector<ll> v){
	ll count =0 ;
	for(int i=0;i<n-1;i++){
		count += d-v[i];
	}
	return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll d;
 	cin>>d;

 	ll n;
 	cin>>n;

 	vector<ll> v(n);
 	for(ll i=0;i<n;i++){
 		cin>>v[i];
 	}   

 	cout<<answer(d , n , v)<<endl;
    return 0;
}