#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

bool placed(int n , int* arr , int mid ,int k){
    int prev = 0 , count = 1;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[prev]>=mid){
            count++;
            prev = i;

            if(count == k){
                return true;
            }
        }
    }
    return count==k;
}
int aggressiveCows(int n , int* arr , int k){
    int s = 0 , e = INT_MAX;
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(placed(n , arr , mid , k)){

            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k ;
    cin>>k;
    sort(arr , arr+n);
    cout<<aggressiveCows(n , arr , k)<<endl;
    return 0 ;
}