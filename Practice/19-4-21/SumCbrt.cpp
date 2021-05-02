#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

bool isCub(ll v){
    ll n = cbrt(v)+1;
    ll i = 1 , j = n;
    while(i<=j){
        ll val = (ll)pow(i,3) + (ll)pow(j,3);
        if(val==v){
            return true;
        }
        if(val<v){
            i++;
        }else{
            j--;
        }
    }
    return false;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(isCub(n)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}