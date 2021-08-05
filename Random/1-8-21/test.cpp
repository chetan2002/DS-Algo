#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;cin>>n;
    vector<ll> v;
    for(int i=-n;i<=n;i++){
    	v.push_back(i);
    }
    ll sum = 0;
    ll sz = v.size();
    for(int i=0;i<sz;i++){
    	for(int j=0;j<sz;j++){
    		sum+= abs(v[i])+abs(v[j]);
    	}
    }
    cout<<sum<<endl;
    return 0;
}