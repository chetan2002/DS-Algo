#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll fib(ll n){
    if(n<=1){
        return n;
    }

    return fib(n-1)+fib(n-2);
}

ll fibDP(ll n){
    int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}
int main(){
    ll n;
    cin>>n;
    for(auto i=0;i<=n;i++){
        cout<<fib(i)<<" ";
        cout<<fibDP(i)<<endl;
    }
    return 0;
}