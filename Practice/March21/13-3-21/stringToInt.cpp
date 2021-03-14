#include<iostream>
#include<cstring>
using namespace std;

int stoi(char* num , int n){
    if(n==0){
        return 0;
    }
    int last = num[n-1]-'0';

    return stoi(num , n-1)*10 + last;
}

int main(){

    char number[100];
    cin>>number;
    int len = strlen(number);
    cout<<stoi(number , len)<<endl;
    return 0;
}