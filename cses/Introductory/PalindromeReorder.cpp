#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

bool answer(string s){
    vector<int> count(26,0);
    for(auto c: s){
        count[c-'A']++;
    }
    bool one = false;
    char character='0';
    string build ="";
    string rev = "";
    for(int i=0;i<26;i++){
        int c = count[i];
        if(one and c%2==1){
            return false;
        }
        if(c%2==1){
            character = 'A'+i;
            one = true;
        }
        int dig = c/2;
        string a(dig, 'A'+i);
        build+=a;
        rev = a+rev;
    }

    if(character=='0'){
        build = build + rev;
    }else{
        build = build+ character + rev;
    }
    cout<<build<<endl;
    return true;
}
int main(){
    string s;
    cin>>s;
    if(!answer(s)){
        cout<<"NO SOLUTION"<<endl;
    }
    return 0;
}