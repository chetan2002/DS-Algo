#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool CowsPlaced(vector<ll> a , ll N , ll C , ll mid){
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

ll answer(vector<ll> a , ll N , ll C){
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	string s;
 	cin>>s;
	ll k;
	cin>>k;
	vector<ll> v;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			v.push_back(i+1);
		}
	}   
	ll n = v.size();
	cout<<answer(v , n , k)<<endl;

    return 0;
}