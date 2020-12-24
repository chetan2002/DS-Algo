#include<iostream>
using namespace std;

int sol[1000][1000]={0};
bool findpath(char arr[1000][1000] , int m , int n , int i , int j){
    if(i==m-1 and j==n-1){
        sol[i][j]=1;

        for(int k=0;k<m;k++){
            for(int l=0;l<n;l++){
                cout<<sol[k][l]<<" ";
            }
            cout<<endl;
        }

        return true;
    }
    if(i<0 || i>=m){
        return false;
    }
    if(j<0 || j>=n){
        return false;
    }
    //recursive
    sol[i][j]=1;
    //right
    if(j+1<n and arr[i][j+1]!='X' and sol[i][j+1]!=1){
        bool path = findpath(arr , m , n , i , j+1);
        if(path){
            return true;
        }
    }

    //down
    if(i+1<m and arr[i+1][j]!='X' and sol[i+1][j]!=1){
        bool path = findpath(arr , m , n , i+1 , j);
        if(path){
            return true;
        }
    }

     //left
    if(j-1>=0 and arr[i][j-1]!='X' and sol[i][j-1]!=1){
        bool path = findpath(arr , m , n , i , j-1);
        if(path){
            return true;
        }
    }

    //up
    if(i-1>=0 and arr[i-1][j]!='X' and sol[i-1][j]!=1){
        bool path = findpath(arr , m , n , i-1 , j);
        if(path){
            return true;
        }
    }

    sol[i][j] = 0;

    return false;
}

int main(){
    int m,n;
    cin>>m>>n;
    char arr[1000][1000];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    bool path = findpath(arr , m , n , 0,0);
    if(!path){
        cout<<"NO PATH FOUND"<<endl;
    }
    return 0;
}
