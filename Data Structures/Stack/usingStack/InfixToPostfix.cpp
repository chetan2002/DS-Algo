#include<bits/stdc++.h>
using namespace std;
unordered_map<char , int> mp;

bool precedence(char c1 , char c2){
    return mp[c2]>=mp[c1];
}

void showstack(stack <char> s) 
{ 
    while (!s.empty()) 
    { 
        cout<< s.top()<<" "; 
        s.pop(); 
    } 
    cout << '\n'; 
} 
bool isOpening(char c){
    if(c=='(' || c=='{' || c=='['){
        return true;
    }
    return false;
}
bool isClosing(char c){
    if(c==']' || c=='}' || c==')'){
        return true;
    }
    return false;
}
bool isBracket(char c){
    if(isOpening(c) || isClosing(c)){
        return true;
    }
    return false;
}
bool isOperator(char c){
    if(mp[c]>0){
        return true;
    }
    return false;
}

string convertInfixToPostfix(string s){
    string a;
    stack<char> stac;
    for(auto c: s){
       // showstack(stac);
        if(isOperator(c)){
            if(!stac.empty() && precedence(c,stac.top())){
                    
                while(!stac.empty() && (precedence(c,stac.top()))){
                    if(isOpening(stac.top())){
                        break;
                    }
                    a+=stac.top();
                    stac.pop();
                    
                }
            }
            stac.push(c);
        }else
        if(isBracket(c)){
            if(isOpening(c)){
                stac.push(c);
            }else
            if(isClosing(c)){
                while(!stac.empty()){
                    if(isOpening(stac.top())){
                        stac.pop();
                        break;
                    }
                    a+=stac.top();
                    stac.pop();
                }
            }
        }else{
            a+=c;
        }
    }
    while(!stac.empty()){
        a+=stac.top();
        stac.pop();
    }
    return a;

}

int main(){
    string s;
    cin>>s;
    mp['+'] = 12;
    mp['-'] = 12;
    mp['*'] = 13;
    mp['/'] = 13;
    mp['%'] = 13;
    mp['|'] = 6;
    mp['^'] = 7;
    mp['&'] = 8;

    cout<<convertInfixToPostfix(s)<<endl;
    return 0;
}
