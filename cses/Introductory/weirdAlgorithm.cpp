#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll answer(ll n){
    if(n%2==0){
        return n/2;
    }
    return (n*3)+1;
}

int main(){
    ll n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        n = answer(n);
        cout<<n<<" ";
    }
    cout<<endl;
    return 0;
}