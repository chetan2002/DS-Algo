#include<bits/stdc++.h>
using namespace std;
#define ll long long int 


void answer(ll n){
    ll ans = 0;
    ll val = 5;
    ll sol = n/val;
    ans+=sol;
    while(sol!=0){
        val = val*5;
        sol = n/val;
        ans+=sol;
    }
    cout<<ans<<endl;
}    
int main(){
   ll n;
   cin>>n;
   answer(n);
   return 0;
}