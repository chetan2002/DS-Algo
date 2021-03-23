#include<iostream>
#include<list>
using namespace std;

template<typename T>
class stack{
    list<T> l1;
    int cr;
public:
    stack(){
        cr = 0;
    }
    void push(T d){
        l1.push_front(d);
        cr++;
    }

    void pop(){
        l1.pop_front();
        cr--;
    }
    int size(){
        return cr;
    }
    T top(){
        return l1.front();
    }
    bool empty(){
        return cr==0;
    }
};


int main(){

    return 0;
}