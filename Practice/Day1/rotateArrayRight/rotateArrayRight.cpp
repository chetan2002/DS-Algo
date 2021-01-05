//https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0#
#include<iostream>
using namespace std;

int * rotateArray(int arr[] , int n , int k ){
    int *a = new int[n];
    for(int i=0;i<n;i++){
        a[(i+k)%n] = arr[i];
    }
    return a;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        arr = rotateArray(arr , n , 1);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}