#include<iostream>
using namespace std;

template <class T>
class Vector{
    private:
        T *arr ;
        int cs ;
        int ms;
    public: 
        Vector(int s=2){
            ms = s ;
            cs = 0;
            arr = new T[ms];
        }
        void push_back(T data){
            if(cs==ms){
                T *oldArr = arr;
                int oldMs = ms;
                arr = new T[2*ms];
                ms*=2;
                for(int i=0;i<oldMs;i++){
                    arr[i]=oldArr[i];
                }
                delete [] oldArr;
            }
            arr[cs++] = data;
        }

        void pop_back(){
            if(cs>0){
                cs--;
            }
        }
        bool empty(){
            if(cs==0){
                return true;
            }
            return false;
        }
        int size(){
            return cs;
        }
        int capacity(){
            return ms;
        }
        T operator[](int i){
            return arr[i];
        }
};

int main(){
    Vector<int> a;
    for(int i=0;i<5;i++){
        a.push_back(i);
    }
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

    return 0 ;
}
