#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	vector<ll> v(n);
 	for(auto &i: v){
 		cin>>i;
 	}   
 	ll maxi = LLONG_MIN , sum = 0;
 	for(auto c: v){
 		sum = max(sum+c , c);
 		maxi = max(maxi , sum);
 	}
 	cout<<maxi<<endl;
    return 0;
}