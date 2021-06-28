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
        vector<string> v={"Alice" , "Bob"};
    	
        if(n%2==1){
            cout<<v[1]<<endl;
        }else
        if(__builtin_popcountll(n)==1 and ((int)log2(n))%2==1){
            cout<<v[1]<<endl;
        }else{
            cout<<v[0]<<endl;
        }

    }
    return 0;
}