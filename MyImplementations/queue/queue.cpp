#include<iostream>
#include<list>
using namespace std;

template<typename T>
class queue{
    list<T> L;
    int cr;
public:
    queue(){
        cr=0;
    }
    void push(T d){
        L.push_back(d);
        cr++;
    }
    void pop(){
        L.pop_front();
        cr--;
    }
    T front(){
        return L.front();
    }
    size_t size(){
        return cr;
    }
    bool empty(){
        return cr==0;
    }
    
};

int main(){

    return 0;
}