#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n,k;
    	cin>>n>>k;

    	ll value = 0;
        for(ll i=0;i<n;i++){
            if(i==0){
                value = 0;
            }else{
                value = (i)^(i-1);
            }
            cout<<value<<endl;
            cout.flush();
            int val;cin>>val;
            if(val==0){
                continue;
            }else{
                break;
            }
        }

    }
    return 0;
}