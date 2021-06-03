#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        
        ll x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        
        ll total = 0;
        ll start = 1;
        for(int i=2;i<=x1;i++){
            start+=i;
        }
        for(int j=1;j<y1;j++){
            start+=(x1+j-1);
        }
        for(int i=x1;i<x2;i++){
            total+=start;
            start+=(i+y1);
        }
        for(int i=y1;i<=y2;i++){
            total+=start;
            start+=(i+x2-1);
        }
        cout<<total<<endl;
    }
    return 0;
}