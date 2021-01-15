//https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
#include<bits/stdc++.h>
using namespace std;

void moveNegative(int a[] , int n){
    int i=0 ;
    int x = 0;
    for(int j=0;j<n;j++){
        if(a[j]<x){
            swap(a[i],a[j]);
            i++;
        }
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    moveNegative(arr , n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0 ;
}