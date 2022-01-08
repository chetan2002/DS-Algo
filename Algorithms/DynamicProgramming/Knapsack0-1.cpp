#include<bits/stdc++.h>
using namespace std;

int KnapsackRec(int *price , int* weight , int capacity , int n){
    if(n==0 or capacity == 0){
        return 0;
    }
    int op1 = INT_MIN, op2 = INT_MIN;
    if(weight[n-1]<=capacity){
        op1 = price[n-1] + KnapsackRec(price , weight , capacity-weight[n-1] , n-1);
    }
    op2 = KnapsackRec(price , weight , capacity , n-1);
    return max(op1 , op2);
}

int topDown(int *price , int *weight , int capacity , int n , int dp[][100]){
    if(n==0 or capacity==0){
        return dp[capacity][n] = 0;
    }
    if(dp[capacity][n]!=-1){
        return dp[capacity][n];
    }
    int op1 = INT_MIN, op2 = INT_MIN;
    if(weight[n-1]<=capacity){
        op1 = price[n-1] + topDown(price , weight , capacity-weight[n-1] , n-1 ,dp);
    }
    op2 = topDown(price , weight , capacity , n-1 , dp);
    return dp[capacity][n] = max(op1 , op2);
    
}

int bottomUp(int *price , int *weight , int capacity , int n){
    int dp[100][100] ={0};
    
    for(int i=1 ; i<=n ; i++){
        for(int j=1; j<=capacity ; j++){
            int op1 = INT_MIN , op2 = INT_MIN;
            if(j>=weight[i-1]){
                op1 = price[i-1] + dp[i-1][j-weight[i-1]];
            }
            op2 = dp[i-1][j];
            dp[i][j] = max(op1 , op2);
        }
    }
    return dp[n][capacity];
}

int main(){
    int price[] = {5, 12, 8, 1};
    int weight[] = {4, 8, 5, 3};
    int n = sizeof(weight)/sizeof(int);
    int capacity = 10;
    int dp[100][100];
    memset(dp , -1 , sizeof(dp));
    cout<<bottomUp(price , weight , capacity , n)<<endl;
    cout<<KnapsackRec(price , weight , capacity , n)<<endl;
    cout<<topDown(price , weight , capacity , n , dp)<<endl;
    return 0;
}