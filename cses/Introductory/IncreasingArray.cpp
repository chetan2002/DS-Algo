#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll answer(ll n , vector<ll> &v){
    if(n==1){
        return 0;
    }
    ll ans = 0;
    ll prev = 0;
    for(auto c: v){
        if(c>=prev){
            prev = c;
        }else{
            ans+= (prev-c);
        }
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;i++){
        ll val;
        cin>>val;
        v.push_back(val);
    }
    cout<<answer(n , v)<<endl;
    return 0;
}