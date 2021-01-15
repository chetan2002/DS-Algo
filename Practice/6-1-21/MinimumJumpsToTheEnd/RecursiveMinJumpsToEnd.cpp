//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#
//Answer : TLE

#include<bits/stdc++.h>
using namespace std;

// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    if(n==1){
        
        return 0;
    }
    int result = INT_MAX;
    for(int i = n-2;i>=0;i--){
        int resultSmall = minJumps(arr , i+1);
        if(resultSmall!=INT_MAX){
            result = min(resultSmall , result);
        }
    }
    return result;
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