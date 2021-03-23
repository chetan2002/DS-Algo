#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
class stack{
    vector<T> v;
public:
    stack(){

    }

    void push(T d){
        v.push_back(d);
    }

    T pop(){
        if(v.size()==0){
            //error
            return -1;
        }
        T val = v.back();
        v.pop_back();
        return val;
    }

    void print(){
        reverse(v.begin(),v.end());
        for(auto c: v){
            cout<<c<<" ";
        }
        reverse(v.begin(),v.end());
        cout<<endl;
    }

    bool empty(){
        return v.size()==0;
    }

    int size(){
        return v.size();
    }

    T top(){
        return v.back();
    }

};


int main(){
    stack<int> s;
    for(int i=0;i<10;i++){
        s.push(i);
    }
    s.print();
    while(!s.empty()){
        cout<<s.pop()<<" ";
    }
    cout<<endl;
    return 0;
}