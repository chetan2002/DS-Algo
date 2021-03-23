#include<iostream>
#include<cstring>
using namespace std;
#define MAX_SIZE 10000

template<typename T>
class stack{
    T *arr;
    int cr;
    int ms;
public:
    stack(){
        arr = new T[MAX_SIZE];
        cr = 0;
        ms = MAX_SIZE;
    }

    void push(T d){
        if(cr==MAX_SIZE){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[cr] = d;
        cr++;
    }

    void pop(){
        if(cr==0){
            cout<<"Stack Underflow"<<endl;
            return;
        }

        cr--;
    }

    size_t size(){
        return cr;
    }

    size_t maxSize(){
        return ms;
    }

    bool empty(){
        return cr==0;
    }

    T top(){
        if(cr!=0){
            return arr[cr-1];
        }
    }
};
int main(){
    stack<int> s;
    for(int i=1000;i<1050;i++){
        s.push(i);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}