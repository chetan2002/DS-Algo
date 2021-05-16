#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n;
    cin>>n;
    unordered_map<ll,ll> mp;
    for(int i=0;i<n;i++){
        ll val;
        cin>>val;
        mp[val]++;
    }
    ll count = 0;
    for(auto c: mp){
        count = max(count , c.second);
    }
    cout<<count<<endl;
    return 0;
}