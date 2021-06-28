#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , k;
 	cin>>n>>k;
 	vector<ll> v(n);
 	for(auto &i: v){
 		cin>>i;
 	}   

 	sort(v.begin(),v.end());
 	int i = 0 , j = n-1;
 	ll count =0 ;
 	while(i<=j){
 		ll sum = v[i]+v[j];
 		if(sum<=k){
 			count++,i++,j--;
 		}else
 		{
 			j--;
 			count++;
 		}
 	}
 	cout<<count<<endl;
    return 0;
}