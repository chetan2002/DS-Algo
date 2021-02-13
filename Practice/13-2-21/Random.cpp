//N Queens

#include<bits/stdc++.h>
using namespace std;


bool isSafe(int board[][10] , int i , int j , int n){
    //You can check for the col
    for(int row=0;row<i;row++){
        if(board[row][j]==1){
            return false;
        }
    }

    //you can check for left diagonal
    int x=i;
    int y=j;

    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }

    return true;
}

bool NQueen(int board[10][10] , int n , int i){
    if(i==n){
        
        for(int i=0 ; i<n; i++){
            for(int j=0 ;j<n;j++){
                if(board[i][j]==1){
                    cout<<"Q ";
                }else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        return true;
    }

    for(int j=0;j<n;j++){
        if(isSafe(board , i , j , n)){
            board[i][j] = 1;
            bool NextQueenPossible = NQueen(board , n , i+1);
            if(NextQueenPossible){
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main(){
    int board[10][10] = {0};
    int n;
    cin>>n;
    NQueen( board , n , 0);
    return 0;
}
