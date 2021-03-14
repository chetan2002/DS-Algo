#include<iostream>
#include<cstring>
using namespace std;

void permutate(char* s ,int i , int len){
    if(i==len){
        cout<<s<<endl;
    }
    for(int j=i;j<len;j++){
        swap(s[i] , s[j]);
        permutate(s , i+1 , len);
        swap(s[i] , s[j]);

    }
}

int main(){
    char S[100];
    cin>>S;
    int len=strlen(S);
    permutate(S ,0 , len);
    return 0;
}