//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

#include<bits/stdc++.h>
using namespace std;

void sort012count(int a[] , int n){
    int count0 = 0 , count1 = 0 , count2 = 0 ;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            count0++;
        }else 
        if(a[i]==1){
            count1++;
        }else{
            count2++;
        }
    }
    for(int i=0;i<n;i++){
        if(count0!=0){
            a[i]=0;
            count0--;
        }else
        if(count1!=0){
            a[i]=1;
            count1--;
        }else{
            a[i]=2;
            count2--;
        }
    }
}
void sort012(int a[], int n)
{
    // coode here 
    long long int ptr0 =0 , ptr2 = n-1;
    for(long long int i=ptr0;i<=ptr2;){
        if(a[i]==0){
            swap(a[i],a[ptr0]);
            ptr0++;
            i++;
        }else
        if(a[i]==2){
            swap(a[i],a[ptr2]);
            ptr2--;
        }else{
            i++;
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort012(arr , n);
    
    for(auto c: arr){
        cout<<c<<" ";
    }
    return 0;
}