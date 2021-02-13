#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll RecursivePath(ll grid[20][20] , int i , int j ){
    if(i==0 and j == 0){
        return grid[i][j];
    }
    if(i<0 || j<0){
        return INT_MAX;
    }
   
    ll op1 , op2;
    op1 = RecursivePath(grid , i-1 , j);
    op2 = RecursivePath(grid , i , j-1);

    return grid[i][j] + min(op1 , op2);
}

ll topDown(ll grid[20][20] , int i , int j , ll dp[20][20]){
    if(i == 0 and j == 0){
        return dp[i][j] = grid[i][j];
    }
    if(i<0 || j<0){
        return INT_MAX;
    }
     if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll op1 , op2 ;
    op1 = topDown(grid , i-1 , j , dp);
    op2 = topDown(grid , i , j-1 , dp);

    return dp[i][j] = grid[i][j] + min(op1 , op2);
}

ll bottomUp(ll grid[20][20] , int m , int n){
    ll dp[20][20] ;
    dp[0][0] = grid[0][0];
    for(int i=1;i<=m;i++){
      dp[i][0] = grid[i][0] + dp[i-1][0];
    }
    for(int j=1 ; j<=n ; j++){
        dp[0][j] = grid[0][j] + dp[0][j-1];
    }
    for(int i = 1 ; i<=m ;i++){
        for(int j = 1 ; j<=n ;j++){
            dp[i][j] = grid[i][j] + min(dp[i][j-1] , dp[i-1][j]);
        }
    }
    return dp[m][n];
}

int main(){
    ll grid[20][20] = {{2, 1 , 3 ,  4 } , 
                        {3 , 1 , 1 , 10} ,
                        {1 , 6 , 1 , 1 } ,
                        {2 , 7 , 4 , 3 }};
        
    int i , j;
    cin>>i>>j;
    
    ll dp[20][20];
    memset(dp , -1 , sizeof(dp));
    cout<<topDown(grid , i , j , dp)<<endl;
    cout<<bottomUp(grid , i , j)<<endl;
    cout<<RecursivePath(grid , i , j)<<endl;

    return 0;
}