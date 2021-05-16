#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    vector<ll> powertwo;
    ll val =1;
    for(int i=0;i<31;i++){
        val= 1<<i;
        powertwo.push_back(val);
    }

    ll n;
    cin>>n;
    vector<ll> v;
    unordered_map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
        mp[val]++;
    }  
    sort(v.begin(),v.end());
    ll count = 0;
    for(ll i=0;i<n;i++){
        bool found = false;
        for(auto c: powertwo){
            ll value = c-v[i];
            if(mp.find(value)!=mp.end()){
                if(value == v[i]){
                    if(mp[value]>1){
                        found=true;
                    }else{
                        continue;
                    }
                }else{
                    found = true;
                }
            }else{
                continue;
            }
        }
        if(!found){
            count++;
        }
    }

    cout<<count<<endl;
    return 0;
}

