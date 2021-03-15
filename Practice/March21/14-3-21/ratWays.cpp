#include<iostream>
using namespace std;

int ratWays(int n , int m){
    if(n==0 and m==0){
        return 1;
    }
    if(n<0 || m<0){
        return 0;
    }
    return ratWays(n , m-1)+ratWays(n-1 , m);
}

int main(){
    int n , m;
    cin>>n>>m;
    cout<<ratWays(n , m)<<endl;
    return 0;
}