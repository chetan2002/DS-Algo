#include<iostream>
using namespace std;

void swap(int &a , int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

void bubbleSort(int n , int arr[100]){
    if(n==0){
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}
void printAr(int n , const int*arr){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void bubbleSortRecur(int n ,int i , int arr[100]){
    if(i==n){
        return;
    }
    for(int j=0; j<n-1;j++){
        if(arr[j]<arr[j+1]){
            swap(arr[j] , arr[j+1]);
        }
    }
    bubbleSortRecur(n , i+1 , arr);
}

void bubbleSortRecurRecur(int n , int i , int j , int arr[100]){
    if(i==n){
        return;
    }
    if(j==n-1){
        bubbleSortRecurRecur(n , i+1 , 0 , arr);
        return;
    }
    if(arr[j]>arr[j+1]){
        swap(arr[j] , arr[j+1]);
    }
    bubbleSortRecurRecur(n , i , j+1 , arr);
}

int main(){
    int n ;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubbleSort(n , arr);
    printAr(n ,arr);
    bubbleSortRecur(n , 0 , arr);
    printAr(n , arr);
    bubbleSortRecurRecur(n , 0 , 0 , arr);
    printAr(n , arr);
    return 0;
}