#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll answer(ll n , ll arr[]){
    ll shouldBe = 0;
    for(ll i=1;i<=n;i++){
        shouldBe = shouldBe^i;
    }
    for(ll i=0;i<n-1;i++){
        ll c = arr[i];
        shouldBe = shouldBe^c;
    }
    return shouldBe;
}

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    cout<<answer(n , arr)<<endl;
    return 0;
}