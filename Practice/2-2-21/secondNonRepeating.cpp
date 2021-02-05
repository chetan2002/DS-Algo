#include<iostream>
#include<string>
using namespace std;

char find_non_repeating(char *arr , int len){
    char result ='-';

    int mem[26]={0};
    for(int i=0; i<len; i++){
        mem[(int)arr[i]-'a']++;
    }

    int count =0;
    for(int i=0 ; i<26 ; i++){
        if(mem[i] == 1){
            count++;
            if(count == 2){
                result = (char)('a'+i);
                break;
            }
        }
    }

    return result;
}

int main(){
    int len;
    char *arr , result;
    cin>>len;
    
    arr = new char(len);
    cin>>arr;
    cout<<find_non_repeating(arr , len);
    
    return 0;
}