#include<iostream>
using namespace std;

int sol[100][100]={0};

bool checkValid(int n , int i , int j){
    //check horizontal
    for(int k=0;k<i;k++){
        if(sol[k][j]==1){
            return false;
        }
    }

    //check diagonal
    int x = i , y = j;
    while(x>=0 and y>=0){
        if(sol[x][y]==1){
            return false;
        }
        x-- , y--;
    }
    x = i , y = j;
    while(x>=0 and y<n){
        if(sol[x][y]==1){
            return false;
        }
        x-- , y++;
    }
    return true;
}

bool NQueens(int n , int i){
    //base case
    if(i==n){
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                cout<<sol[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    //recursive case
    for(int j=0;j<n;j++){
        if(checkValid(n , i , j)){
            sol[i][j] = 1;
            bool missionAcc = NQueens(n , i+1);
            if(missionAcc){
                return true;
            }
            sol[i][j] = 0;
        }
    }

    return false;
}

int main(){
    int n;
    cin>>n;
    
    NQueens(n , 0);

    return 0;
}