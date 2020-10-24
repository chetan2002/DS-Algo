#include<bits/stdc++.h>
using namespace std;

    class Stack{
    
    private:
        vector<int> v;
       
    public:
          Stack(){

          }
          void push(int data){
              v.push_back(data);
          }
          bool isEmpty(){
              return (v.size()==0);
          }
          void pop(){
              if(!isEmpty()){
                  v.pop_back();
              }
          }
          int top(){
              return v[v.size()-1];
          }

};

int main(){
    Stack s;

    for(int i=0;i<6;i++){
        s.push(i*i);
    }
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
