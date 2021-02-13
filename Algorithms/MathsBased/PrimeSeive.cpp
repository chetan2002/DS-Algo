#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
bool prime[100000];

void seivePrime(ll n){
    memset(prime , true , sizeof(prime));

    for(int p = 2 ; p*p<=n ; p++){
        if(prime[p] == true){
            for(int i=p*p ; i<=n ; i+=p){
                prime[i] = false;
            }
        }
    }
}

int main(){
    ll n;
    cin>>n;
    seivePrime(n);
    cout<<prime[7]<<endl;
    cout<<prime[6]<<endl;
    cout<<prime[61]<<endl;
    cout<<prime[633]<<endl;
    cout<<prime[611]<<endl;
    cout<<prime[612]<<endl;

    return 0;
}