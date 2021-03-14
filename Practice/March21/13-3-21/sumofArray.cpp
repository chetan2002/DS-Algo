#include<bits/stdc++.h>
using namespace std;

int sumOfArray(int n , int *arr){
    if(n==0){
        return 0;
    }
    return arr[n-1]+sumOfArray(n-1 , arr);
}

int main(){
    int n ;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<sumOfArray(n , arr)<<endl;
    return 0;
}