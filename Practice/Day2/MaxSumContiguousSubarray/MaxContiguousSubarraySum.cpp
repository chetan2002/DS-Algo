//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
#include<iostream>
using namespace std;


//Kadane's Algorithm
int SumSubarrayMax(int arr[] , int n){
    int maximum = 0 , sum = 0 ;
    for(int i=0;i<n;i++){
        sum = max(sum+arr[i] , arr[i]);
        maximum = max(sum , maximum);
    }
    return maximum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<SumSubarrayMax(arr , n)<<endl;
    return 0 ;
}