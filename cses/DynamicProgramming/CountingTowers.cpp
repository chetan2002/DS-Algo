#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1e9 + 7;


// at every step we have 2 options, either we put a width 2 tile or width 1 tile
// alse we can either extend the previous one or we can put a new one
// let's say A(n) = joint tile, B(n) = seperate tiles
// then A(n) = 2*A(n-1) + B(n-1) and B(n) = 4*B(n-1) + A(n-1)
// how? 
// for A(n), we are putting a joint tile at nth pos
// so either we extend the prev joint tile = A(n-1)
// or put a joint tile above earlier joint tile = A(n-1)
// or put a joint tile about seperate tiles tile = B(n-1) 
// => A(n) = 2*A(n-1) + B(n-1)

// for B(n), we are putting two seperate tiles at nth pos
// so either we extend earlier seperate tiles both side = B(n-1)
// or we extend one side and not other side = 2*B(n-1)
// or we just add two new seperate tiles on older seperate ones = B(n-1)
// or we can put two new seperate tiles on prev joint ones = A(n-1)
// => B(n) = 4*B(n-1) + A(n-1)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    vector<pair<ll,ll>> answer(1e6+1, {0,0});
    answer[1] = {1,1};
    for(int i=2; i<=1e6; i++) {
    	answer[i].first = (2*answer[i-1].first + answer[i-1].second)%mod;
    	answer[i].second = (4*answer[i-1].second + answer[i-1].first)%mod;
    }
    while(t--){
    	ll n;
    	cin>>n;
    	cout<<(answer[n].first + answer[n].second)%mod<<endl;
    }
    return 0;
}