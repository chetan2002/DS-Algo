#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

void answer(ll n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    if(n<=3){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    vector<ll> v;
    int i=2;
    while(i<=n){
        v.push_back(i);
        i+=2;
    }
    i=1;
    while(i<=n){
        v.push_back(i);
        i+=2;
    }

    for(auto c: v){
        cout<<c<<" ";
    }
    cout<<endl;
}

int main(){
    ll n;
    cin>>n;
    answer(n);
    return 0;
}