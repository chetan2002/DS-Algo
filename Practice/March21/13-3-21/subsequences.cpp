#include<iostream>
#include<cstring>
using namespace std;

void subsequences(char* inp , char* out , int i , int j, int n){
    if(i==n){
        out[j] = '\0';
        cout<<out<<endl;
        return ;
    }
    subsequences(inp , out , i+1 , j , n);
    out[j] = inp[i];
    subsequences(inp , out , i+1 , j+1 , n);
}

int main(){
    char inp[100];
    cin>>inp;
    int n = strlen(inp);
    char out[100];
    subsequences(inp , out , 0 , 0, n );
    return 0;
}