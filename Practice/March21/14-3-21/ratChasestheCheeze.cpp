#include <bits/stdc++.h>
using namespace std;
int mat[100][100];

bool solve(char matrix[100][100],int rows,int cols,int i,int j){
    //base case
    if(i==rows-1 and j==cols-1){
        mat[i][j] = 1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        mat[i][j] = 0;
        cout<<endl<<endl;
        return false;
    }
    if(i>=rows or j>=cols or i<0 or j<0){
        return false;
    }
    if(matrix[i][j] == 'X' or mat[i][j]==1){
        return false;
    }
    //recursive case
    mat[i][j] = 1;
    bool right = solve(matrix , rows , cols , i , j+1);
    bool down = solve(matrix , rows , cols , i+1 , j);
    bool up = solve(matrix , rows , cols , i-1 , j );
    bool left = solve(matrix , rows , cols , i , j-1);
    mat[i][j] = 0;
    if(down||right || up || left){
        return true;
    }
    return false;

}
int main() {
    int rows,cols;
    cin>>rows>>cols;
    char matrix[100][100];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cin>>matrix[i][j];
            mat[i][j]=0;
        }
    }
    bool ans=solve(matrix,rows,cols,0,0);
    return 0;
}