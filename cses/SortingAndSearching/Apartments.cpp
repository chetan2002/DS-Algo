#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , m , k ;
 	cin>>n>>m>>k;

 	vector<ll> v(n);
 	for(auto &i: v){
 		cin>>i;
 	}   
 	vector<ll> avail(m);
 	for(auto &i: avail){
 		cin>>i;
 	}

 	sort(v.begin(),v.end());
 	sort(avail.begin(),avail.end());

    int i=0 , j= 0;
    ll count = 0;
    while(i<v.size() and j<avail.size()){
        ll lower = v[i]-k;
        ll upper = v[i]+k;

        if(avail[j]>=lower and avail[j]<=upper){
            count++ , j++ , i++;
        }else
        if(avail[j]<lower){
            j++;
        }else{
            i++;
        }
    }
    cout<<count<<endl;
    return 0;
}