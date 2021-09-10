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
    	string s;cin>>s;

    	int i = -1;
        for(int it=0;it<n;it++){
            if(s[it]=='0'){
                i = it;
                break;
            }
        }
        if(i==-1){
            cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<endl;
            continue;
        }
        if(i<n/2){
            cout<<i+1<<" "<<n<<" "<<i+2<<" "<<n<<endl;
        }else{
            cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<endl;
        }
    }
    return 0;
}