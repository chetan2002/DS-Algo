//Print all solutions for NQueens problem
//https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/

#include<iostream>
using namespace std;

int solution[100][100]={};
bool canPlace(int i , int k , int n){
    
    //horizontal and vertical check
    for(int j=0;j<n;j++){
        if(solution[i][j]==1 || solution[j][k]==1){
            return false;
        }
    }

    //diagonal check right
    int x=i , y=k;
    while(x>=0 and y<n){
        if(solution[x][y]==1){
            return false;
        }
        x--;
        y++;
    }


    //diagonal check left
    x=i , y=k;
    while(x>=0 and y>=0){
        if(solution[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    return true;
}
bool NQueens(int n , int i){
    //base case
    if(i==n){
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                if(solution[k][l]==1){
                    cout<<"Q ";
                }else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    //false cases
    if(i>n){
        return false;
    }

    for(int k=0;k<n;k++){
        if(canPlace(i,k , n)){
            solution[i][k]=1;
            bool forNext = NQueens(n,i+1);
            if(forNext){
                return true;
            }
        }
        solution[i][k]=0;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        NQueens(n , 0);
        cout<<endl;
    }
    return 0 ;
}