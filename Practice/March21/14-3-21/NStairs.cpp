#include<iostream>
using namespace std;

int Stairs(int n ,int k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans+=Stairs(n-i , k);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    cout<<Stairs(n , k)<<endl;
    return 0;
}