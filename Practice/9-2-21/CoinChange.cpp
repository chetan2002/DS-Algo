#include<bits/stdc++.h>
using namespace std;
#define ll long long int 


//recursive function
ll RecursionChange(ll val , ll *arr , ll n){
    if(val == 0){
        return 0;
    }
    ll mini = INT_MAX;
    for(ll i = 0 ; i<n;i++){
        if(val-arr[i]>=0){
            ll smallValue = val-arr[i];
            ll ans = RecursionChange(smallValue , arr , n);
            if(ans!=INT_MAX and smallValue<val){
                mini = ans+1;
            }
        }
         
    }
    return mini;
}

ll topDown(ll val , ll *arr , ll n , ll* dp){
    if(val == 0){
        return dp[val] = 0;
    }
    if(dp[val] != -1){
        return dp[val];
    }
    ll ans = INT_MAX;
    for(int i = 0 ;i < n; i++){
        if(val - arr[i] >= 0){
            ll smallVal = val - arr[i];
            ll smallAns = topDown(smallVal , arr , n , dp);

            if(smallAns!=INT_MAX and smallVal<val){
                ans = smallAns+1;
            }
        }
    }

    return dp[val] = ans;

}

ll bottomUP(ll val , ll *arr , ll n){
    ll *dp = new ll[10000];
    dp[0] = 0;
    for(int i =1 ; i<=val ; i++){
        dp[i] = INT_MAX;
    }
    for(int i=0; i<n ; i++){
        for(int j = 1 ; j<=val ; j++){
            if(j-arr[i]>=0){
                ll smallerAmt = j-arr[i];
                dp[j] = min(dp[smallerAmt]+1 , dp[j]);
            }
        }
    }
    return dp[val];
}

int main(){

    ll arr[] = {1 ,2  , 5 , 10};
    ll n = sizeof(arr)/sizeof(arr[0]);

    ll val;
    cin>>val;
    ll dp[1000000];
    memset(dp , -1 , sizeof(dp));
    cout<<topDown(val , arr , n , dp)<<endl;
    cout<<bottomUP(val , arr , n)<<endl;;
    //cout<<RecursionChange(val , arr , n)<<endl;
    return 0;
}