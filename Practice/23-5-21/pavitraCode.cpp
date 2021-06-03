#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll arr[1001][1001];
ll r , c;

ll answer(int i , int j ){
    if(i<0 || j<0){
        return INT_MAX;
    }
    if(i>=r || j>=c){
        return INT_MAX;
    }
    if(arr[i][j]==9){
        return 0;
    }
    arr[i][j] = 0;
    ll up , down , left , right ;
    up = down = left = right = INT_MAX;
    if(i>0 and arr[i-1][j]!=0){
        up = 1+ answer(i-1 ,j);
    }
    if(j>0 and arr[i][j-1]!=0){
        left =1+ answer(i , j-1);
    }
    if(j<c-1 and arr[i][j+1]!=0){
        right =1+ answer(i , j+1);
    }
    if(i<r-1 and arr[i+1][j]!=0){
        down = 1+answer(i+1 , j);
    }

    return min(up , min( down ,min( left , right)));
}

int  main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    cout<<answer(0,0)<<endl;

    return 0;
}