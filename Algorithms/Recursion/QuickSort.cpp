#include<iostream>
using namespace std;

int partition(int arr[] , int low , int high){
    int i=low;
    int x = arr[high];
    for(int j=low;j<high;j++){
        if(arr[j]<x){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}

void quickSort(int arr[] , int low , int high){
    if(low>high){
        return;
    }
    int pivot = partition(arr , low , high);
    quickSort(arr , low , pivot-1);
    quickSort(arr , pivot+1 , high);
}

int main(){
    int arr[] = {123,134,134,1234,134,324,23,232,4342,2,3423,4,32434,23,3,32,43,13,34};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr , 0 , n-1);
    for(auto c: arr){
        cout<<c<<" ";
    }
    return 0 ;
}
