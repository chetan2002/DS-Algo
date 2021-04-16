#include<bits/stdc++.h>
using namespace std;
// 4 5 1 2 3 
int searchInSortedRotatedArray(int *arr , int target , int n ){
    if(n==0){
        return -1;
    }
    int s =0 , e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[s]<=arr[mid]){
            if(target>=arr[s] and target<arr[mid]){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }else{
            if(target>arr[mid] and target<=arr[e]){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    int a[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;

    cout<<searchInSortedRotatedArray(a , k , n);
    
    return 0;
}