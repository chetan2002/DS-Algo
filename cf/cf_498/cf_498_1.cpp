#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++ ){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        if(v[i]%2==0){
            v[i]=v[i]-1;
        }
    }
    for(auto c: v){
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}