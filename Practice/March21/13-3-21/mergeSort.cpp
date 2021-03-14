#include<iostream>
using namespace std;

void merge(int s , int e , int *arr){
    int mid = (s+e)/2;
    int i=s , j = mid+1  , k=0;
    int newAr[s+e+1];
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            newAr[k++] = arr[i++];
        }else{
            newAr[k++] = arr[j++];
        }
    }
    while(i<=mid){
        newAr[k++] = arr[i++];
    }
    while(j<=e){
        newAr[k++] = arr[j++];
    }
     k=0;
    for(int i=s;i<=e;i++){
        arr[i] = newAr[k++];
    }
}

void mergeSort(int s , int e , int *arr){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(s , mid , arr);
    mergeSort(mid+1 , e , arr);

    merge(s , e , arr);
}

void print(int n , int* arr){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(0 , n-1 , arr);
    print(n , arr);
    return 0;
}
