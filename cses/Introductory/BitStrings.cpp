#include<bits/stdc++.h>
using namespace std;
#define ll long long int 


void answer(ll n){
    ll ans = 1;
    for(int i=0;i<n;i++){
        ans = ans<<1;
        ans = ans%1000000007;
    }
    cout<<ans<<endl;
}    
int main(){
   ll n;
   cin>>n;
   answer(n);
   return 0;
}