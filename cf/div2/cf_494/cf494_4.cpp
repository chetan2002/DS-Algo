#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n , q;
    cin>>n>>q;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> fre(40,0);
    for(auto c: v){
        fre[log2(c)]++;
    }
    while(q--){
        ll total = 0;
        cin>>total;

        ll count = 0;
        for(int i=32;i>=0;i--){
            if(fre[i]==0){
                continue;
            }
            ll val = 1<<i;
            if(val>total){
                continue;
            }
            ll value = total/val;
            ll co = min(value , fre[i]);
            total = total-(val*co);
            count+=co;
            if(total==0){
                break;
            }
        }

        if(total==0){
            cout<<count<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}