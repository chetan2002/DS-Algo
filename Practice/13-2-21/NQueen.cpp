#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[10][10] , int n , int i , int j){

    //horizontal
    for(int k=0 ; k<=j ; k++){
        if(board[i][k]==1){
            return false;
        }
    }
    //vertical
    for(int k=0 ; k<=i ; k++){
        if(board[k][j] == 1){
            return false;
        }
    }

    //left diagonal
    int x=i , y=j;
    while(x>=0 and y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    x=i , y=j;
    //right diagonal
    while(x>=0  and y<n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool NQueen(int board[10][10] , int n , int i){
    //base case
    if(i==n){
        for(int i=0 ;i<n;i++){
            for(int j=0 ; j<n ;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return true;
    }
    //recursive case

    for(int j=0 ; j<n ; j++){
        if(isSafe(board , n , i , j)){
            board[i][j] = 1;
            bool possibleForChotaBoard = NQueen(board , n , i+1);
            if(possibleForChotaBoard){
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main(){

    // 1 0 0 0
    // 0 0 0 1
    // 0 0 0 0
    // 0 0 0 0

    int board[10][10] = {0};
    int n;
    cin>>n;

    NQueen(board , n , 0);

    return 0;
} 

