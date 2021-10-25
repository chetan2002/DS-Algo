#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool prime[100004];
vector<ll> primes;
void seivePrime(ll n){
    memset(prime , true , sizeof(prime));
    for(ll p = 2 ; p*p<=n ; p++){
        if(prime[p] == true){
            primes.push_back(p);
            for(ll i=p*p ; i<=n ; i+=p){
                prime[i] = false;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    unordered_set<ll> v;
    
    seivePrime(100000);
    for(auto c: primes) {
        ll value = c;
        while(value<(ll)10000000000000000) {
            v.insert(value);
            value= value*c;
        }
    	cout<<c<<endl;
    }

    // while(t--){
    //     ll n ;
    //     n = t+1;
        
    //     if(n%2 == 0 ){
    //         cout << 2*n << " "<< n<<endl;
    //     }else {
    //         for(auto c: v) {
    //             if(v.find(n+c)!=v.end()){
    //                 cout<<n+c<<" "<<c<<endl;
    //                 break;
    //             }
    //         }
    //     }
    // }
    return 0;
}