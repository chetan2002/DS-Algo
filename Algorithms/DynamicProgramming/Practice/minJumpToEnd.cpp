#include<bits/stdc++.h>
using namespace std;

void recursive(int n  , int *arr , int pos , int count , int &minCount){
    if(pos==n){
        minCount = min(minCount , count);
        return ;
    }
    


}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count =0 , minCount = INT_MAX;
        recursive(n , arr , 0 , 0 , minCount);
    }
    return 0;
}