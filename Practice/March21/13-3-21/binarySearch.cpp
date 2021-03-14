#include<iostream>
using namespace std ;

class bs{
public:
    bool found;
    int pos;
};

bs binarySearch(int st , int end , int* arr , int k){
    if(st>end){
        return {false , -1};
    }
    int mid = (st+end)/2;
    if(arr[mid]==k){
        return {true , mid};
    }else
    if(arr[mid]>k){
        return binarySearch(st , mid-1 , arr , k);
    }else{
        return binarySearch(mid+1 , end , arr , k);
    }
}

void binarySearchIterative(int n , int *arr , int k){
    int s = 0 , end = n-1;
    while(s<=end){
        int mid = (s+end)/2;

        if(arr[mid]==k){
            cout<<"Found at pos "<<mid<<endl;
            return ;
        }else
        if(arr[mid]>k){
            end = mid-1;
        }else{
            s = mid+1;
        }
    }
    cout<<"Not found"<<endl;
    return;
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
    auto p = binarySearch(0 , n-1 , arr , k);
    if(p.found){
        cout<<"Found At pos "<<p.pos<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    binarySearchIterative(n , arr , k);
    return 0;
}