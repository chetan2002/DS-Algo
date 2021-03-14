#include<iostream>
#include<string>
using namespace std;


string moveXToEnd(string s , int n){
    if(n==0){
        return "";
    }
    string a = s.substr(0,1);
    // cout<<a<<endl;
    string baaki = moveXToEnd(s.substr(1) , n-1);
    if(a=="x"){
        baaki+=a;
    }else{
        baaki = a+baaki;
    }
    return baaki;
}

int main(){
    string s;
    cin>>s;
    cout<<moveXToEnd(s , s.length())<<endl;
    return 0;
}