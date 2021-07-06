#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> prime(100005,1);
vector<ll> primes;
ll mod = 1000000007;
void seivePrime(ll n){
    for(int p = 2 ; p*p<=n ; p++){
        if(prime[p] == 1){
            for(int i=p*p ; i<=n ; i+=p){
                prime[i] = -1;
            }
        }
        if(prime[p]==1){
            for(int i=p;i<=n;i*=p){
                prime[i]=p;
            }
        }
    }

    for(int i=4;i<=100005;i++){
        if(prime[i]!=-1){
            primes.push_back(prime[i]);
        }
    }
}

ll answer(ll n){
	// if(n==1){
	// 	return 2;
	// }
    ll ans = 0;
    ans += (2*((n+1)/2))%mod;
    ans += (3*(n/2))%mod;
    ll value = 6;
    for(auto c: primes){
        ans += (n/value);
        ans = ans%mod;
        // cout<<ans<<" "<<value<<endl;
        value= value*c;
        if(value>n){
            break;
        }
    }
    // cout<<value<<endl;
    return ans%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    seivePrime(100000);
    // for(auto c: primes){
    //     cout<<c<<" ";
    //     if(c>20){
    //         break;
    //     }
    // }
    while(t--){
    	ll n;
    	cin>>n;
    	cout<<answer(n)<<endl;
    }
    return 0;
}