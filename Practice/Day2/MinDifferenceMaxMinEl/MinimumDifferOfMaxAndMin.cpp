//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#


//fails on testcase
// where n = 10 , k = 4
// arr = {6,1,9,1,1,7,9,5,2,10}
//correct answer = 5 
//My answer = 6


#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    // code here
    if(n==1){
        return 0;
    }
    sort(arr , arr+n);
    
    int ans = arr[n-1] - arr[0];
    int small = arr[0]+k;
    int big = arr[n-1]-k;
    if(small>big){
        swap(small , big);
    }

    for(int i=1;i<n-1;i++){
        int sub = arr[i]-k;
        int add = arr[i]+k;

        if(sub >= small || add <= big){
            continue;
        }

        if(big-sub <= add-small){
            small = sub;
        }else{
            big = add ;
        }
    }
    return min(ans , big-small);
    
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<getMinDiff(arr , n , k);
    return 0;
}