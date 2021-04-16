#include<iostream>
using namespace std;

int firstOccurance(int a[] , int n , int key){
    int s = 0 ;
    int e = n-1;
    int ans = -1 ;

    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==key){
            ans = mid;
            e = mid-1;
        }else
        if(a[mid]<key){
            s = mid+1;
        }else{
            e= mid-1;
        }
    }
    return ans;
}

int lastOccurance(int a[] , int n , int key){
    int s =0 ;
    int e = n-1;
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(key == a[mid]){
            ans = mid;
            s = mid+1;
        }else
        if(key<a[mid]){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {1 , 2 , 4 , 8 , 8 , 8 , 8 , 8 , 8 , 10 , 12 , 15 , 21};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key=8; 
    // cin>>key;

    //first and last occurance of a key in sorted array
    cout<<firstOccurance(arr , n , key)<<endl;
    cout<<lastOccurance(arr , n , key)<<endl;

    return 0;
}