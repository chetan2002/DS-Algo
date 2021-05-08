#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll answer(ll n){
    ll total = (n*n)*((n*n)-1);
    ll neg = 4*2 + 8*3 + 4*(n-4)*4 + 4*4 + 4*(n-4)*6 + (n-4)*(n-4)*8;
    return (total-neg)/2;
}

int main(){
   ll n;
   cin>>n;
   for(int i=1;i<=n;i++){
       cout<<answer(i)<<"\n";
   }
   return 0;
}