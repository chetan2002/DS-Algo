#include<bits/stdc++.h>
using namespace std;


int EditDistanceRecur(char *s1 , char *s2 , int i , int j){
    if(i==0){
        return j;
    }
    if(j==0){
        return i;
    }

    if(s1[i-1] == s2[j-1]){
        return EditDistanceRecur(s1 , s2 , i-1 , j-1);
    }else{
        int op1 = EditDistanceRecur(s1 , s2 , i-1 , j-1); //replace
        int op2 = EditDistanceRecur(s1 , s2 , i , j-1);     //insert
        int op3 = EditDistanceRecur(s1 , s2 , i-1 , j);     //Delete
        return 1+min(op1 , min(op2 , op3));
    }
}

int topDown(char* s1 , char *s2 , int i  , int j , int dp[][100]){
    if(i==0){
        return j;
    }
    if(j==0){
        return i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i-1]==s2[j-1]){
        dp[i][j] = topDown(s1 , s2  , i-1 , j-1 , dp);
    }else{
        int op1 = topDown(s1 , s2  , i-1 , j-1 , dp);
        int op2 = topDown(s1 , s2  , i-1 , j , dp);
        int op3 = topDown(s1 , s2  , i , j-1 , dp);
        dp[i][j] = 1+min(op1 , min(op2 , op3));
    }
    return dp[i][j];
}

int bottomUp(char* s1 , char* s2 , int n , int m){
    int dp[n+1][m+1] = {0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j] , min(dp[i-1][j-1] , dp[i][j-1]))+1;
            }
        }
    }
    return dp[n][m];
}

int main(){
    char s1[100];
    char s2[100];
    int n , m;
    cin>>n>>s1;
    cin>>m>>s2;
    int dp[100][100]; 
    memset(dp , -1 , sizeof(dp));
    cout<<topDown(s1 , s2 , n , m , dp)<<endl;
    cout<<bottomUp(s1 , s2 , n , m)<<endl;
    cout<<EditDistanceRecur(s1 , s2 , n , m)<<endl;
    return 0;
}