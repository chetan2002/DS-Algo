//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#
//TLE


#include<bits/stdc++.h>
using namespace std;

// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
    if(arr[0]==0){
        return -1;
    }
    int array[n] ;
    for(int i=1;i<n;i++){
        array[i] = n;
    }
    array[0] = 0;
    int arrayfinal = n;
    for(int i=0;i<n;i++){
        int val = arr[i];
        if(array[i]>=array[n-1]-1){
            continue;
        }
        int score = array[i];
        for(int j=i+1;j<n and j<=i+val;j++){
            array[j] = min(array[j] , score+1);
        } 
        if(array[i]==n and i!=n-1){
            return -1;
        }
        if(array[n-1]<n){
            arrayfinal=array[n-1];
        }
    }
    if(arrayfinal == n){
        for(int i=0;i<n-1;i++){
            if(arr[i]!=1){
                return -1;
            }
        }
    }
    return arrayfinal;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends