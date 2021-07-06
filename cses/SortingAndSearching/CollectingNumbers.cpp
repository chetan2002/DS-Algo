#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	

 	ll n;cin>>n;
 	vector<ll> v(n) , b(n);
 	for(auto &i: v){
 		cin>>i;i--;
 	}   
 	for(int i=0;i<n;i++){
 		b[v[i]] = i;
 	}
 	ll count = 1;
 	for(int i=1;i<n;i++){
 		if(b[i]<b[i-1]){
 			count++;
 		}
 	}
 	cout<<count<<endl;
    return 0;
}