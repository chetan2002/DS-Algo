#include<iostream>
using namespace std;


bool isSafe(char board[][10] , int row , int col , int n){
    //check conditions
}

bool NQueens(char board[][10] , int row  , int n){
    if(row == n){
        //print condition
    }

    for(int col = 0 ; col < n; col++){
        if(isSafe(board , row , col , n) == true){

            board[row][col] = 1;
            bool put = NQueens(board , row+1 , n);
            if(put){
                return true;
            }
        }
    }
    return false;
}

int main(){

    return 0;
}