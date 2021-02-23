//https://hack.codingblocks.com/app/contests/2022/281/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll girls[50005] , boys[5005] , dp[5005][5005];

ll recur(ll i , ll j){
    //base case
    if(i==0){
        return 0;
    }
    if(j==0){
        return INT_MAX;
    }
    //recursive case
    ll op1 = recur(i , j-1);
    ll op2 = recur(i-1 , j-1) + abs(boys[i-1] - girls[j-1]);

    return min(op1 , op2);
}

ll topDown(ll i , ll j){
    if(i==0){
        return dp[i][j] = 0;
    }
    if(j==0){
        return dp[i][j] = INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    ll op1 = topDown(i , j-1);
    ll op2 = topDown(i-1 , j-1 ) + abs(boys[i-1] - girls[j-1]);

    return dp[i][j] = min(op1 , op2);
}

int main(){
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>boys[i];
	}
	for(int j=0 ; j<m ; j++){
		cin>>girls[j];
	}
    sort(boys , boys+n);
    sort(girls ,girls+m);
    memset(dp , -1 , sizeof(dp));
    // cout<<recur(n , m)<<endl;
    cout<<topDown(n , m)<<endl;
	return 0;
}
