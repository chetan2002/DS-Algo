#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Queue{
    stack<T> s1,s2;
public:
    void push(T data){
        s1.push(data);
    }
    void transfer(stack<T> &s1 ,stack<T> &s2){
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

    }
     int size(){
        return (s1.size()+s2.size());
    }
    bool isEmpty(){
        return (size() == 0);
    }
    void pop(){
        if(!isEmpty()){
            transfer(s1,s2);
            s2.pop();
            transfer(s2,s1);
        }
       
    }
    T front(){
        T value = 0;
        if(!isEmpty()){
                   transfer(s1,s2);
                    value = s2.top();
                    transfer(s2,s1);
        }
        return value;

    }
   
};

int main(){
    Queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    cout<<q1.front()<<endl;
    q1.pop();
    while(!q1.isEmpty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    return 0;
}
