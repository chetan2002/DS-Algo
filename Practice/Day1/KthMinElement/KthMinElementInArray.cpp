//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#

#include<bits/stdc++.h>
using namespace std;


int partition(int arr[] , int l , int r){
    int i = l ;
    int j = l;
    int x = arr[r];

    while(j<r){
        if(x>arr[j]){
            swap(arr[j] , arr[i] );
            i++;
        }
        j++;
    }
    swap(arr[i] , arr[r]);
    return i;
}

int RandomPartition(int arr[] , int l , int r ){
    int n = r-l+1;
    int random = rand()%n;
    swap(arr[random+l] , arr[r]);
    return partition(arr , l , r);
}

int KthMin(int arr[] , int l , int r , int k){
    if(k>0 and k<=r-l+1){
        int pivot = RandomPartition(arr , l , r);
        
        if( pivot-l == k-1){
            return arr[pivot];
        }else 
        if( pivot-l > k-1 ){
            return KthMin(arr , l , pivot-1 , k);
        }

        //else if k is in right part
        return KthMin( arr , pivot + 1 , r , k-pivot + l -1);

    }
    return -1;
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
    cout<<KthMin(arr , 0 , n-1 , k);
    return 0;
}