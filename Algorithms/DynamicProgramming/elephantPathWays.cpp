#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//tell the number of ways for elephant to reach destination

ll recursive(int n , int m){
    if(m==0 and n==0){
        return 1;
    }
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum+= recursive(n-i-1 , m);
    }
    for(int j = 0 ;j<m; j++){
        sum+= recursive(n , m-j-1);
    }
    return sum;
}

ll topDown(int n , int m , ll dp[100][100]){
    if(m==0 and n==0){
        return dp[n][m] = 1;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    ll sum = 0;
    for(int i=0;i<n;i++){
        sum+= topDown(n-i-1 , m , dp);
    }
    for(int j = 0 ;j<m; j++){
        sum+= topDown(n , m-j-1 , dp);
    }
    return dp[n][m] =   sum;

}

ll bottomUp(int n , int m){
    ll dp[n+1][m+1];
    for(int i=0 ; i<=n;i++){
        for(int j = 0; j<=m;j++){
            if(i==0 and j==0){
                dp[i][j] = 1;
                continue;
            }
            
            int sum = 0;
            for(int k =0;k<i;k++){
                sum+=dp[k][j];
            }
            for(int k=0;k<j;k++){
                sum+=dp[i][k];
            }
            dp[i][j] = sum;
        }
    }
    return dp[n][m];
}

int main(){
    int n ,m ;
    cin>>n>>m;
    ll dp[100][100];
    memset(dp , -1 , sizeof(dp));
    cout<<bottomUp(n-1 , m-1)<<endl;
    cout<<topDown(n-1 , m-1 , dp)<<endl;
    cout<<recursive( n-1 , m-1)<<endl;
    return 0;
}