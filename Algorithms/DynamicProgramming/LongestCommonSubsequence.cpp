#include<bits/stdc++.h>
using namespace std;

int recursiveLCS(char * s1 , char * s2 , int i , int j){
    if(s1[i]=='\0' || s2[j]=='\0'){
        return 0;
    }

    //recursive case
    if(s1[i] == s2[j]){
        return 1 + recursiveLCS(s1 , s2 , i+1 , j+1);
    }else{
        return max(recursiveLCS(s1 , s2 , i , j+1) , recursiveLCS(s1 , s2 , i+1 , j));
    }
}


int topDown(char * s1 , char *s2 , int i , int j , int dp[100][100]){
    if(s1[i]=='\0' || s2[j]=='\0'){
        return dp[i][j]=0;
    }
    if(dp[i][j]!= -1){
        return dp[i][j];
    }
    //recursive case
    if(s1[i] == s2[j]){
        return dp[i][j]=1 + topDown(s1 , s2 , i+1 , j+1 , dp);
    }else{
        dp[i][j+1] = topDown(s1 , s2 , i , j+1 , dp) ;
        dp[i+1][j] = topDown(s1 , s2 , i+1 , j , dp);
        return dp[i][j] = max(dp[i][j+1],dp[i+1][j] );
    }
}

int bottomUp(char * s1 , char *s2){
    int dp[100][100] = {0};
    int n = strlen(s1);
    int m = strlen(s2);

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    char s1[100] , s2[100];
    cin>>s1>>s2;
    int dp[100][100];
    memset(dp , -1 , sizeof(dp));
    cout<<bottomUp(s1 , s2)<<endl;
    cout<<topDown(s1 , s2 , 0 ,  0 , dp)<<endl;
    cout<<recursiveLCS(s1 , s2 , 0  ,0 )<<endl;
    return 0;
}