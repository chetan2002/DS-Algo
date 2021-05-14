#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    unordered_map<ll , vector<ll>> mp;
    ll sum =0;
    for(ll i=0;i<n;i++){
        sum+=v[i];
        mp[sum].push_back(i);
    }
    sum=0;
    for(ll j=1;j<=n;j++){
        sum+=v[n-j];
        mp[sum].push_back(n-j);
    }
    ll maximum = 0;
    for(auto c: mp){
        if(c.second.size()==2){
            if(c.second.at(0)>=c.second.at(1)){
                continue;
            }
            maximum = max(maximum,c.first);
        }
    }
    cout<<maximum<<endl;
    return 0;
}