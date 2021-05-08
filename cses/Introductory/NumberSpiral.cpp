#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int 

ll answer(ll x, ll y){
    ll ans = 0;
    if(x>=y){
        if(x%2==0){
            ans = x*x - y+1;
        }else{
            ans = (x-1)*(x-1) + y;
        }
    }else{
        if(y%2==0){
            ans = (y-1)*(y-1) + x;
        }else{
            ans = (y*y) - x+1;
        }
    }
    return ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x , y;
        cin>>x>>y;
        cout<<answer(x,y)<<endl;
    }
}