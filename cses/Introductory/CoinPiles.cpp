#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

bool answer(ll a, ll b){
    if(a<b){
        swap(a,b);
    }

    if(a>2*b){
        return false;
    }else{
        a = a%3;
        b = b%3;
        if(a<b){
            swap(a,b);
        }
        if((a==2 and b==1) or (a==0 and b==0)){
            return true;
        }
    }
    return false;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        if(answer(a,b)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}