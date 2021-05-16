#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll val;
        cin>>val;
        v.push_back(val);
    }

    ll sum =0;
    for(auto c: v){
        if(c==1){
            sum++;
        }
    }
    cout<<sum<<endl;

    for(int i=1;i<n;i++){
        if(v[i-1]>=v[i]){
            cout<<v[i-1]<<" ";
        }
    }
    cout<<v[n-1]<<endl;
    return 0;
}