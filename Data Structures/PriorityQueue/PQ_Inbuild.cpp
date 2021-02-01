#include<bits/stdc++.h>
using namespace std;


class MyComp{
public: 
    bool operator()(int a  , int b){
        return a>b;
    }
};

int main(){
    // MAX HEAP
    // priority_queue<int> h;
    // int n;
    // cin>>n;
    // for(int i=0;i<n ; i++){
    //     int val;
    //     cin>>val;
    //     h.push(val);
    // }
    // while(!h.empty()){
    //     cout<<h.top()<<" ";
    //     h.pop();
    // }

    //MIN HEAP
    priority_queue<int , vector<int> , MyComp> h;
    //can use greater<int> for inbuilt comparator
    //check why we have to pass vector??
    int n;
    cin>>n;
    for(int i=0;i<n ; i++){
        int val;
        cin>>val;
        h.push(val);
    }
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
    return 0;
}