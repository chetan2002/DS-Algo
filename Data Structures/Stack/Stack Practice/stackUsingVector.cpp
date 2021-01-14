#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Stack{
    vector<T> v;
public: 
    int top(){
        return v[v.size()-1];
    }

    void push(T data){
        v.push_back(data);
    }

    void pop(){
        v.pop_back();
    }

    int size(){
        return v.size();
    }

    bool isEmpty(){
        return (v.size()==0);
    }
};

int main(){
    Stack<char> s1;
    for(int i=65;i<75;i++){

        s1.push(i);
    }
    while(!s1.isEmpty()){
        char val = s1.top();
        s1.pop();
        cout<<val<<" ";
    }
    return 0;
}