#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

vector<string> keypad={"" , "ABC" , "DEF" , "GHI" , "JKL" , "MNO" , "PQRS" , "TUV" , "WX" , "YZ"};

void keypadDecode(char* in , char *out , int i , int n){
    if(i == n){
        out[i]='\0';
        cout<<out<<endl;
        return;
    }
    int j=in[i]-'0';

    for(int k=0;k<keypad[j].length();k++){
        out[i] = keypad[j][k];
        keypadDecode(in , out , i+1 , n);
    }
}

int main(){
    char in[100];
    cin>>in;
    int n=strlen(in);
    char out[100];
    keypadDecode(in , out , 0  , n);
    return 0;
}