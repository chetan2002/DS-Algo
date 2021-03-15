#include<iostream>
using namespace std;

void selectionSort(int* arr , int n , int i ){
    if(i==n){
        return;
    }
    int mini = i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[mini]){
            mini = j;
        }
    }
    swap(arr[i] , arr[mini]);
    selectionSort(arr , n , i+1);
}

void print(int *arr , int n ){
    if(n==0){
        return ;
    }
    int c = arr[n-1];
    print(arr , n-1);
    cout<<c<<" ";
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr , n , 0);
    print(arr , n);
    return 0 ;
}