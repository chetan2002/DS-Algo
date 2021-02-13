//you are given array of n wines and each wine cost A[i]*NoOfDay 
//and you are allowed to sell from either left or right side
//maximize the profit

#include<bits/stdc++.h>
using namespace std ;

int topDown(int *arr , int l , int r , int day , int dp[][100]){
    if(l>r){
        return dp[l][r] = 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    int op1 = day*arr[l] + topDown(arr , l+1 , r , day +1  , dp);
    int op2 = day*arr[r] + topDown(arr , l , r-1 , day +1 , dp);

    return dp[l][r] = max(op1 , op2);
}

int recursiveSolution(int *arr , int l , int r , int day){
    if(l>r){
        return 0 ;
    }
    int op1 = 0 , op2 = 0 ;
    //if right
    op1 = day*arr[r] + recursiveSolution(arr , l , r-1 , day+1);

    //if left
    op2 = day*arr[l] + recursiveSolution(arr , l+1 , r , day+1);

    return max(op1 , op2);
}

int bottomUp(int *arr , int n){
    if(n==0){
        return 0;
    }
    int dp[n+1][n+1] = {0};
    for(int i=n-1 ; i>=0 ; i--){
        for(int j = 0; j<n ;j++){
            int day = n - (j - i);
            if(i<j){
                
                dp[i][j] = max(day*arr[i] + dp[i+1][j]  , day*arr[j] + dp[i][j-1]);
            }else
            if(i==j){
                dp[i][j] = day*arr[i];
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int arr[] = {2 , 3, 5 , 1 , 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dp[100][100]; 
    for(int i=0;i<100 ; i++){
        for(int j = 0 ; j<100 ; j++){
            dp[i][j] = -1;
        }
    }
    cout<<bottomUp(arr , n)<<endl;
    cout<<topDown(arr , 0 , n-1 , 1 , dp)<<endl;
    cout<<recursiveSolution(arr , 0 , n-1 , 1)<<endl;
    return 0;
}