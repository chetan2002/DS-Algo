#include<iostream>
using namespace std;

template<class T>
class Vector{
    T *arr ;
    int cs ;
    int ms;

    void resize(){
        ms = ms*2;
        T* newAr = new T[ms];
        for(int i=0;i<cs;i++){
            newAr[i] = arr[i];
        }
        delete []arr;
        arr= newAr;
    }
    void merge(int s , int e){
        int mid = (s+e)/2;
        int i = s , j = mid+1 , k = 0;
        T temp[e-s+1];
        while(i<=mid and j<=e){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }else{
                temp[k++] = arr[j++];
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=e){
            temp[k++] = arr[j++];
        }
        k = 0;
        for(i=s;i<=e;i++){
            arr[i] = temp[k++];
        }
    }
    void mergesort(int s , int e){
        if(s>=e){
            return;
        }
        int mid = (s+e)/2;
        mergesort(s , mid);
        mergesort(mid+1 , e);
        merge(s , e);
    }
public:
    Vector(){
        arr = new T[2];
        cs = 0 ;
        ms =2;
    }
    Vector(int size , int in = 0){
        arr = new T[size];
        memset(arr , in , sizeof(arr));
        cs = 0;
        ms = size;
    }
    void push_back(T d){
        if(cs==ms){
            resize();
        }
        arr[cs++] = d;
    }

    T pop_back(){
        if(cs==0){
            return -1;
        }
        return arr[cs--];
    }

    T at(int i){
        if(i>cs || i<0){
            return -1;
        }
        return arr[i];
    }

    bool empty(){
        if(cs==0){
            return true;
        }
        return false;
    }

    size_t size(){
        return cs;
    }

    size_t capacity(){
        return ms;
    }

    T operator[](int i){
        return arr[i];
    }

    void sort(){
        int  n = cs;
        mergesort(0 , n-1);
    }
};

int main(){
    int n;
    cin>>n;
    Vector<int> v;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }
    v.sort();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}