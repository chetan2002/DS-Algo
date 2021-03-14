#include<iostream>
using namespace std;

void printAs(int n ){
    if(n<0){
        return;
    }
    printAs(n-1);
    cout<<n<<" ";
}

void printDes(int n){
    if(n==0){
        cout<<"0"<<endl;
        return;
    }
    cout<<n<<" ";
    printDes(n-1);

}

int main(){
    int n= 10;
    printAs(n);
    cout<<endl;
    printDes(n);

    return 0;
}