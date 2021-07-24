#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
        vector<ll> v(n);
        for(auto &i: v){
            cin>>i;
        }
        vector<ll> vA(n,0);
        for(int i=1;i<n;i++){
            vA[i] = (v[i-1]^vA[i-1])&(~v[i]);
        }
        for(auto c: vA){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}