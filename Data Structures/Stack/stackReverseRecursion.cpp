#include<bits/stdc++.h>
using namespace std;

void recursionReverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    recursionReverse(s);
    s.push(x);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    recursionReverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
