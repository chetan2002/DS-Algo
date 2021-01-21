#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool CowsPlaced(ll *a , ll N , ll C , ll mid){
    ll PlacedCows = 1;
    ll prevInd = 0;
    for(ll i=1; i<N ; i++){
        if(a[i] - a[prevInd] >= mid){
            PlacedCows++;
            prevInd = i;
            if(PlacedCows == C){
                return true;
            }
        }
    }
    return PlacedCows==C;
}

ll aggressiveCows(ll *a , ll N , ll C){
     ll s = 0 ;
     ll e = INT_MAX;
     ll ans = -1;
     while(s<=e){
          ll mid = (s+e)/2;
          if(CowsPlaced(a , N ,C , mid)){
              s = mid+1;
              ans = max( ans , mid);
          }else{
              e = mid-1;
          }
     }
     return ans;
}

int main(){
    ll n , c;
    cin>>n>>c;
    ll *a = new ll[n];
    for(ll i=0 ; i < n ; i++ ){
        cin>>a[i];
    }
    sort(a , a+n);

    cout<< aggressiveCows(a , n , c) << endl;

    return 0;
}