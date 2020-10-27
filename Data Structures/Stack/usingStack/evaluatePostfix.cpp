#include<bits/stdc++.h>
using namespace std;

int value(char a){
    return (int)(a-'0');
}

int op(int a , int b , char c){
    switch(c){
        case '+' : return a+b;
        case '-' : return a-b;
        case '*' : return a*b;
        case '/' : return a/b;    
    }
    return 0;
}
bool isNum(char c){
    if(c>='0' && c<='9'){
        return true;
    }
    return false;
}

long long int evaluatePostfix(string s){
    stack<int> stac;
    for(auto c: s){
        if(isNum(c)){
            stac.push(value(c));
        }else{
            int v1 =stac.top();
            stac.pop();
            int v2 = stac.top();
            stac.pop();
            v1 = op(v2,v1,c);
            stac.push(v1);
        }
    }
    return stac.top();
}

int main(){
    string s;
    cin>>s;
    cout<<evaluatePostfix(s)<<endl;
    return 0;
}
