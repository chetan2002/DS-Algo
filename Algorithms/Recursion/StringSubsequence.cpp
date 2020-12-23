#include<iostream>
using namespace std;

void subseq(char *in , int i , char *out , int j){

    //base case
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }

    subseq(in , i+1 , out , j);

    out[j] = in[i];
    subseq(in , i+1 , out , j+1);
}

int main(){

    char a[100];
    cin>>a;
    char out[100];
    subseq(a , 0 , out , 0);
    cout<<endl;
    return 0 ;
}
